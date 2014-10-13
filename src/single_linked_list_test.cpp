#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "single_linked_list.h"

TEST(SingleLinkedList, IntegerIterator)
{
    SingleLinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    for (int e : list) {
        printf("%d ", e);
    }
    printf("\n");
}

TEST(SingleLinkedList, StringIterator)
{
    SingleLinkedList<string> list;
    list.add("Pablo");
    list.add("Rendon");
    list.add("Rafael");

    for (string& e : list) {
        cout << e << " ";
        e += "-";
    }
    cout << endl;

    for (string e : list) {
        cout << e << " ";
    }

    cout << endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
