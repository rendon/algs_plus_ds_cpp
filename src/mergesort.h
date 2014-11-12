#ifndef MERGESORT_H_
#define MERGESORT_H_
#include <iostream>
using namespace std;

class MergeSort {
private:
    void merge(int A[], int T[], int a, int b, int c, int d) {
        int i = a;
        int j = c;
        int p = a;
        while (i < b && j < d) {
            if (A[i] <= A[j]) {
                T[p++] = A[i++];
            } else {
                T[p++] = A[j++];
            }
        }

        while (i < b) {
            T[p++] = A[i++];
        }

        while (j < d) {
            T[p++] = A[j++];
        }

        for (int k = a; k < p; k++) {
            A[k] = T[k];
        }
    }

    void sort(int A[], int T[], int l, int r) {
        if (l + 1 >= r) { return; }
        int mid = (l + r) / 2;
        sort(A, T, l, mid);
        sort(A, T, mid, r);
        merge(A, T, l, mid, mid, r);
    }
public:
    void sort(int A[], int n) {
        if (n < 2) { return; }

        int *T = new int[n];
        if (!T) {
            cerr << "Unable to allocate memory." << endl;
        }

        sort(A, T, 0, n);

        delete T;
    }
};

#endif
