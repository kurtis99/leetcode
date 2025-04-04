#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>

using namespace std;


int findPivot(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) return nums[0] == target ? 0 : -1;

    int lo = 0;
    int hi = nums.size() - 1;
    if (!(target >= nums[0] && target <= nums[nums.size() -1])) {
        int pivot = findPivot(nums);
        if (nums[pivot] == target) return pivot;
        if (target >= nums[pivot] && target <= nums[hi]) {
            lo = pivot;
            hi = nums.size() - 1;
        } else {
            lo = 0;
            hi = pivot - 1;
        }
    }
    if (lo >= nums.size() || hi >= nums.size()) return -1;
    if (nums[lo] == target) return lo;
    if (nums[hi] == target) return hi;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;

        if (target < nums[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

void doTest(vector<int> nums, int target, int expected) {
    int ret = search(nums, target);
    if (ret == expected) {
        cout << "[PASSED] ";
    } else {
        cout << "[FAILED] ";
    }
    cout << target << " [";
    for (auto num : nums) {
        cout << " " << num;
    }
    cout << "] -> " << expected << " got " << ret << endl;
}

int main() {

    doTest( {4,5,6,7,0,1,2}, 0, 4);
    doTest( {4,5,6,7,0,1,2}, 3,-1);
    doTest( {4,5,6,7,0,1,2}, 5, 1);
    doTest( {1}, 0, -1);
    doTest( {3,1}, 3, 0);
    doTest( {1,3}, 3, 1);
    doTest( {5,1,3}, 3, 2);

    return 0;
}
