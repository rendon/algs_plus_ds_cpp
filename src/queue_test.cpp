#include <iostream>
#include "gtest/gtest.h"
#include "queue.h"

using namespace std;

TEST(Queue, IntegersPushAndPop) {
    Queue<int> Q;
    for (int i = 0; i < 10; i++) {
        Q.push(i);
    }

    while (Q.size() > 0) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
}

TEST(Queue, StringsPushAndPop) {
    Queue<string> Q;
    Q.push("first");
    Q.push("second");
    Q.push("third");
    Q.push("fourth");
    Q.push("fifth");

    while (Q.size() > 0) {
        cout << Q.front() << " ";
        Q.pop();
    }

    cout << endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
