//
// Created by murmur wheel on 2020/9/26.
//

#ifndef FRAMEWORK_UTIL_REF_COUNT_H
#define FRAMEWORK_UTIL_REF_COUNT_H

#include <type_traits>

#include "util_common.h"

namespace framework {
class RefCount {
 public:
  RefCount() = default;
  virtual ~RefCount() = default;

  int add_ref() { return ++count_; }
  int sub_ref() { return --count_; }

 private:
  int count_{1};

  DISABLE_COPY_AND_MOVE(RefCount)
};

template <typename T>
class DefaultDx {
 public:
  void operator()(T* ptr) { delete ptr; }
};

template <typename T, typename Dx = DefaultDx<T>>
class RefPtr;

template <typename T>
class RefPtr<T, DefaultDx<T>> {
 public:
  static_assert(std::is_base_of<RefCount, T>(), "T must drive from RefCount");

  using Self = RefPtr<T, DefaultDx<T>>;

  RefPtr() = default;
  explicit RefPtr(T* ptr) : ptr_(ptr) {}
  ~RefPtr() { set(nullptr); }

  RefPtr(const Self& other) : ptr_(nullptr) { set(other.ptr_); }
  RefPtr(Self&& other) noexcept : ptr_(nullptr) {
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  RefPtr<T, DefaultDx<T>>& operator=(const Self& rhs) {
    if (&rhs == this) {
      return *this;
    }

    set(rhs.ptr_);
    return *this;
  }

  RefPtr<T, DefaultDx<T>>& operator=(Self&& rhs) noexcept {
    if (&rhs != this) {
      set(nullptr);
      ptr_ = rhs.ptr_;
      rhs.ptr_ = nullptr;
    }

    return *this;
  }

  void set(T* ptr) {
    if (ptr) {
      ptr->add_ref();
    }

    if (ptr_ && ptr_->sub_ref() == 0) {
      DefaultDx<T>()(ptr_);
      ptr_ = nullptr;
    }

    ptr_ = ptr;
  }

  T* operator->() const { return ptr_; }

 private:
  T* ptr_{nullptr};
};

template <typename T, typename Dx>
class RefPtr {
 public:
  static_assert(std::is_base_of<RefCount, T>(), "T must drive from RefCount");

  using Self = RefPtr<T, Dx>;

  RefPtr() = default;
  RefPtr(const Self& other) : dx_(other.dx_) { set(other.ptr_); }
  RefPtr(Self&& other) noexcept : ptr_(other.ptr_), dx_(std::move(other.dx_)) {}
  ~RefPtr() { set(nullptr); }

  RefPtr(T* ptr, Dx dx) : ptr_(ptr), dx_(std::move(dx)) { set(ptr); }

  RefPtr<T, Dx>& operator=(const Self& rhs) {
    if (&rhs == this) {
      return *this;
    }

    set(rhs.ptr_);
    return *this;
  }

  RefPtr<T, Dx>& operator=(Self&& rhs) noexcept {
    if (&rhs != this) {
      set(nullptr);

      ptr_ = rhs.ptr_;
      dx_ = std::move(rhs.dx_);
      rhs.ptr_ = nullptr;
    }

    return *this;
  }

  void set(T* ptr) {
    if (ptr) {
      ptr->add_ref();
    }

    if (ptr_ && ptr_->sub_ref() == 0) {
      dx_(ptr_);
      ptr_ = nullptr;
    }

    ptr_ = ptr;
  }

  T* operator->() const { return ptr_; }

 private:
  T* ptr_{nullptr};
  Dx dx_;
};
}  // namespace framework

#endif  // FRAMEWORK_UTIL_REF_COUNT_H
