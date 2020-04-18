#include "gtest/gtest.h"

TEST(EQUAL, TRUE)
{
    EXPECT_EQ(1,1);
}

TEST(EQUAL, FALSE)
{
    EXPECT_EQ(1,2);
}