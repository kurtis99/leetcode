#include <iostream>
#include <vector>

using namespace std;





bool canJump(vector<int> nums) {
    bool null_found = false;
    int to_jump_null = 0;

    for (int i = (nums.size() - 1); i >= 0; i--) {
        if (nums[i] == 0 && (null_found == false)) {
            null_found = true;
            to_jump_null = 0;
        }
        if (null_found) {
            to_jump_null++;
        }
        if (nums[i] >= to_jump_null) {
            null_found = false;
            to_jump_null = 0;
        }
    }
    return to_jump_null == 0;
}

int main() {

    int ret;

    ret = canJump( {2, 0} );
    cout << ret << endl;

}
