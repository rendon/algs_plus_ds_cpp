#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"
#include "heap.h"

using namespace std;

TEST(Heap, HeapOfIntegers) {
    Heap<int> h;
    h.insert(7);
    h.insert(1);
    h.insert(9);
    h.insert(100);
    h.insert(-3);
    EXPECT_EQ(5, h.size());
    h.print();
    EXPECT_EQ(100, h.top());
    int A[5];
    h.sort(A);
    EXPECT_EQ(0, h.size());

    cout << A[0] << " ";
    for (int i = 1; i < 5; i++) {
        cout << A[i] << " ";
        EXPECT_TRUE(A[i-1] <= A[i]);
    }
    cout << endl;
}

TEST(Heap, HeapOfStrings) {
    Heap<string> h;
    h.insert("abc");
    h.insert("a");
    h.insert("z");
    h.insert("hsuidf");
    EXPECT_EQ(4, h.size());
    h.print();
    
    EXPECT_EQ("z", h.top());

    h.remove();
    EXPECT_EQ("hsuidf", h.top());
    
    string A[9];
    h.sort(A);
    EXPECT_EQ(0, h.size());

    cout << A[0] << " ";
    for (int i = 1; i < 3; i++) {
        EXPECT_TRUE(!(A[i] < A[i-1]));
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

