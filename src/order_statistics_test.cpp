#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "order_statistics.h"

using namespace std;

TEST(OrderStatisticsTest, NORMAL)
{
    OrderStatistics os;
    int input[] = {9, 5, 1, 12, 15, 4, 7, 14, 3, 8, 0, 11, 17};
    int size = sizeof (input) / sizeof (int);
    ASSERT_EQ(0, os.findK(input, size, 1));
    ASSERT_EQ(17, os.findK(input, size, 13));
    ASSERT_EQ(11, os.findK(input, size, 9));
    ASSERT_EQ(3, os.findK(input, size, 3));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
