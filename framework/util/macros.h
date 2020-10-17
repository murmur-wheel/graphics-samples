//
// Created by murmur wheel on 2020/10/18.
//

#ifndef FRAMEWORK_UTIL_MACROS_H
#define FRAMEWORK_UTIL_MACROS_H

#define DISABLE_COPY_AND_MOVE(NAME)      \
  NAME(const NAME&) = delete;            \
  NAME(NAME&&) = delete;                 \
  NAME& operator=(const NAME&) = delete; \
  NAME&& operator=(NAME&&) = delete;

#endif // FRAMEWORK_UTIL_MACROS_H
