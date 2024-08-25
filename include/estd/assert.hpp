#ifndef ESTD_ASSERT_HPP
#define ESTD_ASSERT_HPP

#include "config.hpp"

namespace estd {

#define Expects(cond, message)                                                 \
  (ESTD_LIKELY(cond) ? static_cast<void>(0) : ESTD_ASSERT(false && message))
#define Ensures(cond, message)                                                 \
  (ESTD_LIKELY(cond) ? static_cast<void>(0) : ESTD_ASSERT(false && message))

} // namespace estd

#endif // ESTD_ASSERT_HPP
