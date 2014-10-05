#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "read_last_lines.h"
using namespace std;

TEST(ReadLastLinesTest, Positive)
{
    stringstream ss1, ss2, ss3, ss4, ss5;
    for (int i = 0; i < 10; i++) {
        ss1 << "Line #" << i << endl;
        ss2 << "Line #" << i << endl;
        ss3 << "Line #" << i << endl;
        ss4 << "Line #" << i << endl;
        ss5 << "Line #" << i << endl;
    }

    ReadLastLines reader;
    ASSERT_TRUE(reader.lastK(ss1, 1));
    cout << endl;

    ASSERT_TRUE(reader.lastK(ss2, 5));
    cout << endl;

    ASSERT_TRUE(reader.lastK(ss3, 8));
    cout << endl;

    ASSERT_TRUE(reader.lastK(ss4, 10));
    cout << endl;
    
    ASSERT_TRUE(reader.lastK(ss5, 15));
    cout << endl;
}

TEST(ReadLastLinesTest, NosPositive)
{
    stringstream ss;
    ReadLastLines reader;
    ASSERT_FALSE(reader.lastK(ss, 0));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
