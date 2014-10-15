#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "single_linked_list.h"

TEST(SingleLinkedList, IntegerIterator)
{
    SingleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    for (int e : list) {
        printf("%d ", e);
    }
    printf("\n");

    printf("Using direct iterator:\n");
    SingleLinkedList<int>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        printf("%d ", *it);
    }

    printf("\n");
}

TEST(SingleLinkedList, StringIterator)
{
    SingleLinkedList<string> list;
    list.push_front("Pablo");
    list.push_front("Rendon");
    list.push_front("Rafael");

    for (string& e : list) {
        cout << e << " ";
        e += "-";
    }
    cout << endl;

    cout << "Using const iterator:\n";
    SingleLinkedList<string>::const_iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        cout << *it << endl << endl;
    }
}

TEST(SingleLinkedList, PushAndPop)
{
    SingleLinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i * i);
    }

    for (int l : list) {
        cout << l << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        list.pop_front();
    }

    for (int l : list) {
        cout << l << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        list.pop_back();
    }

    for (int l : list) {
        cout << l << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
