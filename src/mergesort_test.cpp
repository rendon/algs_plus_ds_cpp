#include <iostream>
#include "gtest/gtest.h"
#include "mergesort.h"

using namespace std;

TEST(MergeSort, PositiveAndNegativeNumbers) {
    int A[] = {50, 0, -30, 100};
    MergeSort ms;
    ms.sort(A, 4);
    for (int i = 1; i < 4; i++) {
        EXPECT_TRUE(A[i-1] <= A[i]);
    }
}

TEST(MergeSort, SingleElement) {
    int A[] = {7};
    MergeSort ms;
    ms.sort(A, 1);
    EXPECT_EQ(7, A[0]);
}

TEST(MergeSort, ManyElements) {
    int A[] = {-100, 0, 100, 22, 5, 3, 3, 3, 9, -1, -400, 16, -400, 0, 0};
    int n = (sizeof A) / (sizeof (int));
    MergeSort ms;
    ms.sort(A, n);
    for (int i = 1; i < n; i++) {
        EXPECT_TRUE(A[i-1] <= A[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
