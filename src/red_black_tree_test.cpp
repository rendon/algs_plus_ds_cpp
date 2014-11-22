#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"

#include "red_black_tree.h"
using namespace std;
TEST(RedBlackTree, RedBlackTreeCreation) {
    vector<int> values = {
        75, 50, 44, 29, 35, 81, 62, 23, 77, 69, 71, 76, 95, 17, 73, 90, 32, 27,
        7, 5, 30, 10, 79, 59, 6, 83, 14, 40, 52, 88, 94, 20, 78, 61, 64, 46, 8,
        15, 47, 80, 25, 72, 63, 43, 28, 68, 56, 87, 11, 21, 9, 54, 12, 51, 58,
        48, 26, 74, 16, 70, 2, 55, 34, 1, 37, 19, 86, 91, 82, 67, 36, 42, 93,
        98, 100, 45, 33, 49, 92, 66, 60, 13, 96, 31, 3, 4, 24, 85, 65, 89, 39,
        41, 99, 97, 84, 22, 38, 53, 57, 18
    };

    RedBlackTree<int> tree;
    //for (int v : values) {
    //    tree.insert(v);
    //}
    for (int i = 0; i < 100; i++) {
        tree.insert(i);
    }
    tree.print();
    cout << "Tree height = " << tree.height() << endl;
    cout << "Tree size = " << tree.size() << endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
