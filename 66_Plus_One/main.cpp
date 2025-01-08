#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>

using namespace std;
vector<int> plusOne(vector<int>& digits) {
    vector<int> ret(digits.size(), 0);

    bool add_leading_one = false;
    ret[digits.size() - 1] = 1;
    for (int i = (digits.size() - 1); i >= 0; i--) {
        int val = digits[i] + ret[i];
        if (val > 9) {
            if (i == 0)
                add_leading_one = true;
            else
                ret[i - 1] += 1;
            ret[i] = val % 10;
        } else {
            ret[i] = val;
        }
    }
    if (add_leading_one)
        ret.insert(ret.begin(), 1);

    return ret;
}

void dump_arr(vector<int>& digits) {
    for (size_t i = 0; i < digits.size(); i++) {
        cout << digits[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> digits_1 = {1,2,3};
    vector<int> digits_2 = {4,3,2,1};
    vector<int> digits_3 = {9};

    vector<int> ret;
    ret = plusOne(digits_1);
    dump_arr(ret);

    ret = plusOne(digits_2);
    dump_arr(ret);

    ret = plusOne(digits_3);
    dump_arr(ret);

    return 0;
}
