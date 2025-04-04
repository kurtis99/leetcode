#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());

    size_t n = nums.size();
    for (size_t i = 0; i < (n - 2); i++) {
        if (i && (nums[i] == nums[i - 1])) continue;

        int lo, hi;
        lo = i + 1;
        hi = n - 1;
        int target = (-1) * nums[i];
        while (lo < hi) {
            if ((lo != (i + 1)) && (nums[lo] == nums[lo-1])) {
                lo++;
                continue;
            }
            if ((hi != (n - 1)) && (nums[hi] == nums[hi+1])) {
                hi--;
                continue;
            }
            if (nums[lo] + nums[hi] == target) {
                ret.push_back( {nums[i], nums[lo], nums[hi]});
                lo++;
                hi--;
            }
            if (nums[lo] + nums[hi] > target)
                hi--;
            if (nums[lo] + nums[hi] < target)
                lo++;
        }
    }

    return ret;
}

void runTest(vector<int> v) {
    vector<vector<int>> ret;
    ret = threeSum(v);
    cout << "------------------------------" << endl;
    for (auto const& vvv : ret) {
        for (auto const& w : vvv) {
            cout << w << " ";
        }
        cout << endl;
    }
}

int main() {
    runTest( {-1,0,1,2,-1,-4} );
    runTest( {-2,0,0,2,2} );

    return 0;
}
