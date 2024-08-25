#ifndef CONFIG_HPP
#define CONFIG_HPP

/// assert
#ifndef ESTD_ASSERT
#include <cassert>
#define ESTD_ASSERT assert
#ifdef NDEBUG
#define ESTD_INNER_IS_ENABLE_PANIC 1
#else // NDEBUG
#define ESTD_INNER_ENABLE_PANIC 0
#endif // NDEBUG
#endif // ESTD_ASSERT

/// likely
#ifndef ESTD_LIKELY
#if defined(__clang__) || defined(__GNUC__)
#define ESTD_LIKELY(x) __builtin_expect(!!(x), 1)
#else
#define ESTD_LIKELY(x) (!!(x))
#endif // defined(__clang__) || defined(__GNUC__)
#endif // ESTD_LIKELY

/// exception
#ifndef ESTD_NOEXCEPT
#define ESTD_NOEXCEPT noexcept
#endif // ESTD_NOEXCEPT

#endif // CONFIG_HPP
