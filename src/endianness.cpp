#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n = 1;
    char *p = (char *)&n;
    if (*p == 1) {
        cout << "Little Endian" << endl;
    } else {
        cout << "Big Endian" << endl;
    }


    union {
        int integer;
        char byte;
    } test;

    test.integer = 1;

    if (test.byte == 1) {
        cout << "Little Endian" << endl;
    } else {
        cout << "Big Endian" << endl;
    }

    return 0;
}
