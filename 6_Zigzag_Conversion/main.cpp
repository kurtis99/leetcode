#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>

using namespace std;

bool shouldWrite(int n, int row, int numRows) {
    int write_idx = numRows - row - 1;
    int n_mod = n % (numRows - 1);
    if (n_mod == 0)
        return true;
    if (n_mod == write_idx)
        return true;
    return false;
}

string convert(string s, int numRows) {
    string res(s.size(), ' ');

    size_t src = 0;
    for (size_t row = 0; row < numRows; row++) {
        int n, idx;
        for (n = 0, idx = 0; idx < s.size(); n++) {
            idx = row + 2 * n;
            if (idx >= s.size())
                break;
            if (shouldWrite(n, row, numRows))
                res[src++] = s[idx];
        }
    }
    return res;
}

int main() {

    string ret;
    ret = convert("PAYPALISHIRING", 3);
    cout << ret << endl;

    return 0;
}
