//
// Created by sinigr on 07.01.2023.
//
#include <gtest/gtest.h>
#include "../lib.h"

TEST(TestVersion, TestValidVersionGeneration) {
    EXPECT_EQ(version() > 0, true);
}