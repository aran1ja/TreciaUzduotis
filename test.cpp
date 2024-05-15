#include "pch.h"
#include <gtest/gtest.h>
#include "vector.h"

TEST(VectorTest, DefaultKonstruktorius) {
    Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
    EXPECT_TRUE(v.empty());
}

TEST(VectorTest, CopyKonstruktorius) {
    Vector<int> v1(5, 10);
    Vector<int> v2(v1);
    EXPECT_EQ(v1.size(), v2.size());
    EXPECT_EQ(v1.capacity(), v2.capacity());
    for (int i = 0; i < v1.size(); ++i) {
        EXPECT_EQ(v1[i], v2[i]);
    }
}

TEST(VectorTest, MoveKonstruktorius) {
    Vector<int> v1(5, 10);
    Vector<int> v2(std::move(v1));
    EXPECT_EQ(v1.size(), 0);
    EXPECT_EQ(v1.capacity(), 0);
    EXPECT_TRUE(v1.empty());
    EXPECT_EQ(v2.size(), 5);
    EXPECT_EQ(v2.capacity(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v2[i], 10);
    }
}

TEST(VectorTest, AssignFunkcija) {
    Vector<int> v;
    v.assign(5, 10);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], 10);
    }
}

TEST(VectorTest, AtFunkcija) {
    Vector<int> v(5, 10);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v.at(i), 10);
    }
    EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, FrontFunkcija) {
    Vector<int> v = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(v.front(), 1);
}

TEST(VectorTest, BackFunkcija) {
    Vector<int> v = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(v.back(), 5);
}
