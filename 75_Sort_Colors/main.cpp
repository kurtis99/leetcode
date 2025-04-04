#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>

#include "readfile.hpp"

using namespace std;


void sortColors(vector<int>& nums) {
    size_t freq[3] = {0};
    for (const auto num: nums) {
        freq[num]++;
    }
    size_t offset = 0;
    for (size_t color = 0; color < 3; color++) {
        if (freq[color] == 0) continue;
        for (size_t i = 0; i < freq[color]; i++) {
            nums[i + offset] = color;
        }
        offset += freq[color];
    }
}

void doTest(vector<int> nums) {
    cout << " [";
    if (!nums.empty()) {
        auto it = nums.begin();
        std::cout << *it++;
        for (; it != nums.end(); ++it) {
            std::cout << " " << *it;
        }
    }
    cout << "] -> [";
    sortColors(nums);
    if (!nums.empty()) {
        auto it = nums.begin();
        std::cout << *it++;
        for (; it != nums.end(); ++it) {
            std::cout << " " << *it;
        }
    }
    cout << "]" << endl;
}

int main() {
    try {
        auto results = parseFile("data.txt");
        for (const auto& [vec, args] : results) {
            doTest(vec);
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
