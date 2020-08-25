// Copyright 2004-present Facebook. All Rights Reserved.

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class Foo {
 public:
  int get3() {
    return 3;
  }
};

class MockFoo : public Foo {
 public:
  MOCK_METHOD0(get3, int());
};

namespace testing {

TEST(FooTest, Simple) {
  MockFoo mfoo;
  EXPECT_CALL(mfoo, get3())
    .WillOnce(Return(10));

  int r = mfoo.get3();
  EXPECT_EQ(r, 10);
}

}
