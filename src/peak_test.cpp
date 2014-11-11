#include <iostream>
#include <utility>
#include <vector>
#include "gtest/gtest.h"
#include "peak.h"
using namespace std;

TEST(Peak, Peak1D) {
    vector<int> A = {1, 2, 3, 5, 0, 3, 1, 3, 8, 9};
    Peak peak;
    int n = A.size();
    int i = peak.find1d(A);
    EXPECT_TRUE((i == 0 && A[i] >= A[1]) ||
                (i == n - 1 && A[i-1] <= A[i]) ||
                (A[i-1] <= A[i] && A[i] >= A[i+1]));
}

TEST(Peak, Peak2D) {
    vector<vector<int> > A = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    Peak peak;
    pair<int, int> p = peak.find2d(A);
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int n = A.size();
    int m = A[0].size();
    bool test = true;
    for (int i = 0; i < 4; i++) {
        int r = p.first + dr[i];
        int c = p.second + dc[i];
        if (r >= 0 && r < n && c >= 0 && c < m) {
            test &= A[p.first][p.second] >= A[r][c];
        }
    }

    EXPECT_TRUE(test);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

