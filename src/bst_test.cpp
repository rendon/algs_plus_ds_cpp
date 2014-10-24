#include <iostream>
#include "gtest/gtest.h"
#include "bst.h"

using namespace std;

TEST(BinarySearchTree, BasicUsage)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(9);
    tree.insert(1);
    tree.insert(12);
    tree.insert(3);
    tree.insert(8);
    tree.insert(7);
    tree.insert(-7);
    tree.insert(88);
    tree.insert(100);
    tree.insert(0);
    tree.insert(-33);


    tree.print();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
