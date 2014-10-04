#ifndef ORDER_STATISTICS_H_
#define ORDER_STATISTICS_H_

#include <bits/stdc++.h>
using namespace std;

class OrderStatistics {
public:
    OrderStatistics()
    {
        srand(time(NULL));
    }

    int findK(int A[], int size, int k)
    {
        if (size < 1 || k < 1 || k > size) {
            return -1;
        }

        return find(A, 0, size, k);
    }
private:
    int partition(int A[], int l, int r)
    {
        if (r <= l) { return -1; }
        int n = r - l;
        int m = l + rand() % n;
        swap(A[l], A[m]);
        int x = A[l];
        int i = l;
        for (int j = l + 1; j < r; j++) {
            if (A[j] <= x) {
                i++;
                swap(A[i], A[j]);
            }
        }

        swap(A[l], A[i]);
        return i;
    }

    int find(int A[], int l, int r, int i)
    {
        if (l + 1 == r) {
            return A[l];
        }

        int p = partition(A, l, r);
        int k = p - l + 1;
        if (k == i) {
            return A[p];
        } else if (i < k) {
            return find(A, l, p, i);
        } else {
            return find(A, p + 1, r, i - k);
        }
    }

};
#endif
