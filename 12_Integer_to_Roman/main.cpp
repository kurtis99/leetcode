#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <functional>


using namespace std;


map<int, string, greater<int> > Rom = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

string intToRoman(int num) {
    string out;
    for (const auto &pair : Rom) {
        cout << pair.first << endl;
        int cnt = num / pair.first;
        num -= cnt * pair.first;
        while (cnt-- > 0) {
            out += pair.second;
        }
    }

    return out;
}

int main() {
    vector<int> nums = {
        3749,
        58,
        1994,
    };

    string ret;
    ret = intToRoman(nums[0]);
    cout << ret << endl;
    ret = intToRoman(nums[1]);
    cout << ret << endl;
    ret = intToRoman(nums[2]);
    cout << ret << endl;

    return 0;
}
