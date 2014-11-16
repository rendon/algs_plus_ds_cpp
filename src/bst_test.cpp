#include <iostream>
#include "gtest/gtest.h"
#include "bst.h"

using namespace std;

TEST(BinarySearchTree, BinarySearchTreeOfIntegers)
{
    BinarySearchTree<int> tree;
    vector<int> elements = {5, 9, 1, 12, 3, 8, 7, 88, 100, 0, -33};
    for (int e : elements) {
        tree.insert(e);
    }

    EXPECT_TRUE(tree.find(9) != nullptr);
    EXPECT_TRUE(tree.find(0) != nullptr);
    EXPECT_TRUE(tree.find(-33) != nullptr);
    EXPECT_TRUE(tree.find(100) != nullptr);

    EXPECT_TRUE(tree.find(800) == nullptr);
    EXPECT_TRUE(tree.find(-1000) == nullptr);

    //tree.print();
}


TEST(BinarySearchTree, BinarySearchTreeOfStrings) {
    BinarySearchTree<string> tree;
    EXPECT_TRUE(tree.find("sdf") == nullptr);
    EXPECT_TRUE(tree.find("") == nullptr);

    tree.insert("");
    EXPECT_TRUE(tree.find("") != nullptr);

    tree.insert("sdf");
    EXPECT_TRUE(tree.find("sdf") != nullptr);

    tree.insert("one");
    string* e = tree.find("one");
    EXPECT_TRUE("one" == *e);
}

TEST(BinarySearchTree, TestFloorAndCeil) {
    BinarySearchTree<int> tree;
    vector<int> elements = {5, 9, 1, 12, 3, 8, 7, 88, 100, 0, -33};
    for (int e : elements) {
        tree.insert(e);
    }

    EXPECT_TRUE(tree.floor(-100) == nullptr);
    EXPECT_TRUE(tree.ceiling(200) == nullptr);

    EXPECT_EQ(12, *tree.ceiling(10));
    EXPECT_EQ(100, *tree.floor(300));

    EXPECT_EQ(0, *tree.floor(0));
    EXPECT_EQ(3, *tree.floor(3));
}

TEST(BinarySearchTree, BinarySearchTreeOfStringMinAndMax) {
    vector<string> elements = {"a", "ab", "z", "wer", "lkj", "za", "zb", "b"};
    BinarySearchTree<string> tree;
    EXPECT_TRUE(tree.min() == nullptr);
    EXPECT_TRUE(tree.max() == nullptr);

    for (string e : elements) {
        tree.insert(e);
    }

    EXPECT_EQ("a", *tree.min());
    EXPECT_EQ("zb", *tree.max());
}

TEST(BinarySearchTree, BinarySearchTreeOfIntegerMinAndMax) {
    BinarySearchTree<int> tree;
    EXPECT_TRUE(tree.min() == nullptr);
    EXPECT_TRUE(tree.max() == nullptr);
    
    vector<int> elements = {5, 9, 1, 12, 3, 8, 7, 88, 100, 0, -33};
    for (int e : elements) {
        tree.insert(e);
    }

    EXPECT_EQ(-33, *tree.min());
    EXPECT_EQ(100, *tree.max());
}

TEST(BinarySearchTree, BinarySearchTreeOfIntegerRankAndSelect) {
    vector<int> elements = {-33, 0, 1, 3, 5, 7, 8, 9, 12, 88, 100};
    BinarySearchTree<int> tree;
    for (int e : elements) {
        tree.insert(e);
    }

    EXPECT_EQ(0, tree.rank(-100));
    EXPECT_EQ((int) elements.size(), tree.rank(101));
    EXPECT_EQ(1, tree.rank(0));
    EXPECT_EQ(5, tree.rank(7));

    EXPECT_EQ(int(elements.size()), tree.size());
    for (int i = 0; i < tree.size(); i++) {
        EXPECT_EQ(elements[i], *tree.select(tree.rank(elements[i])));
    }
}

TEST(BinarySearchTree, BinarySearchTreeDeleteMinMax) {
    vector<int> elements = {-33, 0, 1, 3, 5, 7, 8, 9, 12, 88, 100};
    BinarySearchTree<int> tree;
    for (int e : elements) {
        tree.insert(e);
    }

    int size = elements.size();
    EXPECT_EQ(-33, *tree.min());
    EXPECT_EQ(100, *tree.max());
    EXPECT_EQ(size, tree.size());

    tree.deleteMin();
    tree.deleteMax();
    size -= 2;
    EXPECT_EQ(0, *tree.min());
    EXPECT_EQ(88, *tree.max());
    EXPECT_EQ(size, tree.size());

    tree.deleteMin();
    tree.deleteMax();
    size -= 2;
    EXPECT_EQ(1, *tree.min());
    EXPECT_EQ(12, *tree.max());
    EXPECT_EQ(size, tree.size());

    tree.deleteMin();
    tree.deleteMax();
    size -= 2;
    EXPECT_EQ(3, *tree.min());
    EXPECT_EQ(9, *tree.max());
    EXPECT_EQ(size, tree.size());

    tree.deleteMin();
    tree.deleteMax();
    size -= 2;
    EXPECT_EQ(5, *tree.min());
    EXPECT_EQ(8, *tree.max());
    EXPECT_EQ(size, tree.size());

    tree.deleteMin();
    tree.deleteMax();

    EXPECT_EQ(1, tree.size());
    EXPECT_EQ(7, *tree.select(0));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
