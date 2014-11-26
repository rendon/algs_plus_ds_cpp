#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"

#include "red_black_tree.h"
using namespace std;
vector<int> values = {
    75, 50, 44, 29, 35, 81, 62, 23, 77, 69, 71, 76, 95, 17, 73, 90, 32, 27,
    7, 5, 30, 10, 79, 59, 6, 83, 14, 40, 52, 88, 94, 20, 78, 61, 64, 46, 8,
    15, 47, 80, 25, 72, 63, 43, 28, 68, 56, 87, 11, 21, 9, 54, 12, 51, 58,
    48, 26, 74, 16, 70, 2, 55, 34, 1, 37, 19, 86, 91, 82, 67, 36, 42, 93,
    98, 100, 45, 33, 49, 92, 66, 60, 13, 96, 31, 3, 4, 24, 85, 65, 89, 39,
    41, 99, 97, 84, 22, 38, 53, 57, 18
};

TEST(RedBlackTree, TestHeightWithRandomValues) {

    RedBlackTree<int> tree;
    for (int v : values) {
        tree.insert(v);
    }
    int h = 2 * log2(values.size());
    EXPECT_TRUE(tree.height() <= h);
}

TEST(RedBlackTree, TestHeightWithSequencialValues) {
    RedBlackTree<int> tree;
    int limit = 1000;
    for (int i = 0; i < limit; i++) {
        tree.insert(i);
    }
    int h = 2 * log2(limit);
    EXPECT_TRUE(tree.height() <= h);
}

TEST(RedBlackTree, TestFindAndDeleteMin) {
    RedBlackTree<int> tree;
    for (int v : values) {
        tree.insert(v);
        EXPECT_TRUE(tree.find(v) != tree.end());
    }
    sort(begin(values), end(values));
    EXPECT_EQ(values[values.size()-1], *tree.max());
    for (int v : values) {
        EXPECT_EQ(v, *tree.min());
        tree.deleteMin();
    }
}

TEST(RedBlackTree, TestFindAndDeleteMax) {
    RedBlackTree<int> tree;
    for (int v : values) {
        tree.insert(v);
    }
    sort(begin(values), end(values));
    for (int i = values.size() - 1; i >= 0; i--) {
        EXPECT_EQ(values[i], *tree.max());
        tree.deleteMax();
    }
}

TEST(RedBlackTree, TestDeletion) {
    RedBlackTree<int> tree;
    for (int v : values) {
        tree.insert(v);
    }
    for (int v : values) {
        EXPECT_TRUE(tree.find(v) != tree.end());
        tree.erase(v);
        EXPECT_TRUE(tree.find(v) == tree.end());
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
