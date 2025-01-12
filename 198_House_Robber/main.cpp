#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool near_visit(size_t i, vector<bool>& visited) {
    bool left, right, centr;
    left = right = false;
    if (i != 0)
        left = visited[i - 1];
    if (i != (visited.size() - 1))
        right = visited[i + 1];
    centr = visited[i];
    return (left || right || centr);
}

int rob(vector<int>& nums, vector<bool>& visited) {
    vector<int> total(nums.size(), 0);
    for (size_t i = 0; i < nums.size(); i++) {
        if (near_visit(i, visited))
            continue;
        visited[i] = true;
        total[i] = nums[i] + rob(nums, visited);
        visited[i] = false;
    }

    return *max_element(total.begin(), total.end());
}

int rob(vector<int>& nums) {
    vector<bool> visited(nums.size(), false);
    return rob(nums, visited);
}

int main() {

    int ret;
    vector<int> nums1 {1,2,3,1};
    vector<int> nums2 {2,7,9,3,1};
    vector<int> nums3 {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};

    ret = rob(nums1);
    cout << ret << endl;
    ret = rob(nums2);
    cout << ret << endl;
    ret = rob(nums3);
    cout << ret << endl;

    return 0;
}
