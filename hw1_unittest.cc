#include "gtest/gtest.h"
#include "./hw1.h"

TEST(BoundaryValue, Normal)
{
    EXPECT_EQ(ISOSCELES, CheckTriangle(1, 100, 100));
    EXPECT_EQ(ISOSCELES, CheckTriangle(2, 100, 100));
    EXPECT_EQ(ISOSCELES, CheckTriangle(199, 100, 100));
    EXPECT_EQ(INVALID, CheckTriangle(200, 100, 100));
    EXPECT_EQ(ISOSCELES, CheckTriangle(100, 1, 100));
    EXPECT_EQ(ISOSCELES, CheckTriangle(100, 2, 100));
    EXPECT_EQ(ISOSCELES, CheckTriangle(100, 199, 100));
    EXPECT_EQ(INVALID, CheckTriangle(100, 200, 100));
    EXPECT_EQ(ISOSCELES, CheckTriangle(100, 100, 1));
    EXPECT_EQ(ISOSCELES, CheckTriangle(100, 100, 2));
    EXPECT_EQ(ISOSCELES, CheckTriangle(100, 100, 199));
    EXPECT_EQ(INVALID, CheckTriangle(100, 100, 200));
    EXPECT_EQ(EQUILATERAL, CheckTriangle(100, 100, 100));
}

TEST(BoundaryValue, Robust)
{
    EXPECT_EQ(INVALID, CheckTriangle(0, 100, 100));
    EXPECT_EQ(INVALID, CheckTriangle(-1, 100, 100));
    EXPECT_EQ(INVALID, CheckTriangle(201, 100, 100));
    EXPECT_EQ(INVALID, CheckTriangle(202, 100, 100));
    EXPECT_EQ(INVALID, CheckTriangle(100, 0, 100));
    EXPECT_EQ(INVALID, CheckTriangle(100, -1, 100));
    EXPECT_EQ(INVALID, CheckTriangle(100, 201, 100));
    EXPECT_EQ(INVALID, CheckTriangle(100, 202, 100));
    EXPECT_EQ(INVALID, CheckTriangle(100, 100, 0));
    EXPECT_EQ(INVALID, CheckTriangle(100, 100, -1));
    EXPECT_EQ(INVALID, CheckTriangle(100, 100, 201));
    EXPECT_EQ(INVALID, CheckTriangle(100, 100, 202));
}

TEST(EquivalenceClass, WeakNormal)
{
    //None
    EXPECT_EQ(INVALID, CheckTriangle(100, 1, 2));
    EXPECT_EQ(EQUILATERAL, CheckTriangle(100, 100, 100));
    EXPECT_EQ(ISOSCELES, CheckTriangle(180, 150, 150));
    EXPECT_EQ(UNEQUAL, CheckTriangle(50, 60, 70));

}

TEST(EquivalenceClass, WeakRobust)
{
    EXPECT_EQ(INVALID, CheckTriangle(201, 50, 50));
    EXPECT_EQ(INVALID, CheckTriangle(0, 50, 50));
    EXPECT_EQ(INVALID, CheckTriangle(50, 201, 50));
    EXPECT_EQ(INVALID, CheckTriangle(50, 0, 50));
    EXPECT_EQ(INVALID, CheckTriangle(50, 50, 201));
    EXPECT_EQ(INVALID, CheckTriangle(50, 50, 0));
    EXPECT_EQ(INVALID, CheckTriangle(60, 50, 5));
}

