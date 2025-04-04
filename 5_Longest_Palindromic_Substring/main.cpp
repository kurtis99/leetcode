#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <climits>

using namespace std;


int calcMaxLen(string s, int left, int right) {
    int offset;

    offset = 0;
    while (s[left - offset] == s[right + offset]) {
        offset++;
        if (((left - offset) < 0) || ((right + offset) >= s.size())) {
            break;
        }
    }
    return offset ? ((right + offset - 1) - (left - offset)) : 0;
}

string longestPalindrome(string s) {
    int max_len = 0;
    int max_pos = 0;

    if (s.size() == 1)
        max_len = 1;

    for (size_t i = 0; i < (s.size() - 1); i++) {
        int len1 = 0;
        int len2 = 0;
        if (s[i] == s[i+1])
            len1 = calcMaxLen(s, i, i + 1);
        len2 = calcMaxLen(s, i, i);

        if (len1 > max_len) {
            max_len = len1;
            max_pos = i - ((len1 / 2) - 1);
        }
        if (len2 > max_len) {
            max_len = len2;
            max_pos = i - ((len2 - 1) / 2);
        }
    }

    return s.substr(max_pos, max_len);
}


void runTest(string s, string result) {
    string ret = longestPalindrome(s);
    if (ret != result) {
        std::ostringstream oss;
        oss << "ERR! longestPalindrome(" << s << ")" << " != " << result;
        throw std::runtime_error(oss.str());
    }
    cout << "OK! calculate(" << s << ")" << " == " << ret << endl;
}

int main() {

    try {
        runTest("a", "a");
        runTest("ccc", "ccc");
        runTest("cbbd", "bb");
        runTest("babad", "bab");
    } catch (overflow_error const& e) {
        cout << e.what() << '\n';
    }

    return 0;
}
