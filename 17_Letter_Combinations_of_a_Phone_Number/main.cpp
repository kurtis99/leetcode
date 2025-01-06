#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>

using namespace std;

array<string, 10>  arr = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};

void backtrack(vector<string>& res, string digits, string combination) {
    if (digits.size() == 0) {
        res.push_back(combination);
        return;
    }
    string letters = arr[digits[0] - '0'];
    for (char c : arr[digits[0] - '0']) {
        backtrack(res, digits.substr(1), combination + c);
    }
}

vector<string> letterCombinations(string digits) {
    vector <string> ret;
    if (digits.size() == 0)
        return ret;

    backtrack(ret, digits, "");
    return ret;
}

static void print_result(vector<string>& r) {
    ostringstream oss;
    for (size_t i = 0; i < r.size(); i++) {
        if (i > 0) oss << " ";
        oss << r[i];
    }
    cout << oss.str() << endl;
}

int main() {

    /*
Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:
    Input: digits = ""
    Output: []
Example 3:
    Input: digits = "2"
    Output: ["a","b","c"] */

    vector <string> result = letterCombinations("23");
    print_result(result);

    result = letterCombinations("");
    print_result(result);

    result = letterCombinations("2");
    print_result(result);


    return 0;   
}

