#include "egsl/not_null.hpp"
#include <gtest/gtest.h>

using namespace egsl;

TEST(NotNull, should_dereference_to_same_value) {
  int a = 1234;
  not_null<int> ptr{&a};

  EXPECT_EQ(ptr, &a);
}

TEST(NotNull, should_construct_with_normal_ptr) {
  int a;
  not_null<int> ptr{&a};
}

TEST(NotNull, should_construct_with_normal_const_ptr) {
  int a;
  not_null<const int> ptr{&a};
}

TEST(NotNull, const_should_construct_with_normal_const_ptr) {
  int const a = 1;
  not_null<const int> ptr{&a};
}

#ifdef ESTD_INNER_ENABLE_PANIC
TEST(NotNullDeath, panic_when_construct_with_nullptr) {
  int *ptr_a = nullptr;
  ASSERT_DEATH(not_null<int> ptr{ptr_a}, "pass nullptr to not_null");
}
#endif

TEST(NotNull, should_assign_with_normal_ptr) {
  int a = 0, b = 0;
  not_null<int> ptr{&a};
  ptr = &b;

  EXPECT_EQ(ptr, &b);
}

#ifdef ESTD_INNER_ENABLE_PANIC
TEST(NotNullDeath, panic_when_assign_with_nullptr) {
  int a = 0;
  not_null<int> ptr{&a};
  int *null_ptr = nullptr;
  ASSERT_DEATH(ptr = null_ptr, "pass nullptr to not_null");
}
#endif
