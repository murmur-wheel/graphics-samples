//
// Created by murmur-wheel on 2020/10/20.
//

#ifndef FRAMEWORK_UTIL_WAIT_GROUP_H
#define FRAMEWORK_UTIL_WAIT_GROUP_H

#include <atomic>
#include <condition_variable>
#include <mutex>

namespace framework {
class WaitGroup {
 public:
  void add(int val) { counter_ += val; }

  void done() {
    counter_ -= 1;
    if (counter_ == 0) {
      cv_.notify_one();
    }
  }

  void wait() {
    std::unique_lock<std::mutex> lck(cv_mtx_);
    cv_.wait(lck, [=] { return counter_ == 0; });
  }

 private:
  std::atomic_int32_t counter_;
  std::condition_variable cv_;
  std::mutex cv_mtx_;
};
}  // namespace framework

#endif  // FRAMEWORK_UTIL_WAIT_GROUP_H
