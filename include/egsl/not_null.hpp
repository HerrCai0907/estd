#ifndef EGSL_POINTER_HPP
#define EGSL_POINTER_HPP

#include "config.hpp"
#include "estd/assert.hpp"
#include <cstddef>

namespace egsl {

template <class T> class not_null {
private:
  T *m_t;

public:
  explicit not_null(T *t) ESTD_NOEXCEPT : m_t(t) {
    Expects(m_t != nullptr, "pass nullptr to not_null");
  }

  not_null(not_null const &t) ESTD_NOEXCEPT : m_t(t.m_t) {}
  not_null(not_null &&t) ESTD_NOEXCEPT : m_t(t.m_t) {}
  not_null &operator=(not_null const &t) ESTD_NOEXCEPT {
    m_t = t.m_t;
    return *this;
  }
  not_null &operator=(not_null &&t) ESTD_NOEXCEPT {
    m_t = t.m_t;
    return *this;
  }

  not_null &operator=(T *t) ESTD_NOEXCEPT {
    m_t = t;
    Expects(m_t != nullptr, "pass nullptr to not_null");
    return *this;
  }
  bool operator==(not_null const &t) const ESTD_NOEXCEPT {
    return m_t == t.m_t;
  };
  bool operator!=(not_null const &t) const ESTD_NOEXCEPT {
    return m_t != t.m_t;
  };
  bool operator==(T *t) const ESTD_NOEXCEPT { return m_t == t; };
  bool operator!=(T *t) const ESTD_NOEXCEPT { return m_t != t; };

  not_null(std::nullptr_t) ESTD_NOEXCEPT = delete;
  T &operator*() ESTD_NOEXCEPT { return *m_t; }
};

} // namespace egsl

#endif // EGSL_POINTER_HPP
