#include <iostream>
#include "gtest/gtest.h"
#include "stack.h"
using namespace std;

TEST(StackOfInt, PushTopAndPop) {
    Stack<int> S;
    for (int i = -5; i <= 5; i++) {
        S.push(i);
    }

    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }

    cout << endl;
}

TEST(StackOfString, PushTopAndPop) {
    Stack<string> S;
    S.push("Rendon");
    S.push("Pablo");
    S.push("Rafael");

    cout << S.top() << " ";
    S.pop();
    cout << S.top() << " ";
    S.pop();
    cout << S.top() << " ";
    S.pop();
    cout << endl;
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
