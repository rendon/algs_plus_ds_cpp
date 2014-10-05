#ifndef READ_LAST_LINES_H_
#define READ_LAST_LINES_H_

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class ReadLastLines {
public:
    ReadLastLines() { }
    bool lastK(stringstream &input, int k)
    {
        if (input.bad()) {
            cerr << "Bad file." << endl;
            return false;
        }

        if (k < 1) {
            cerr << "K must be positive." << endl;
            return false;
        }

        string *lines = new string[k];
        if (!lines) {
            cerr << "Couln't allocate memory." << endl;
            return false;
        }

        int count = 0;
        int l = 0;
        string line;
        while (getline(input, line)) {
            lines[l] = line;
            l = (l + 1) % k;
            count++;
        }

        if (count < k) {
            for (int i = 0; i < l; i++) {
                cout << lines[i] << endl;
            }
        } else {
            for (int i = 0; i < k; i++) {
                cout << lines[(l+i)%k] << endl;
            }
        }

        return true;
    }
};
#endif
