#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>




/*
1)  1 1 1 1 2 2 3 3 3 3
last_seen_val = 1
last_seen_idx = 0
*/




int removeDuplicates(int nums[], int numsSize) {
    int last_seen_val = nums[0];
    int last_seen_idx = 0;
    int copy_index=0;
    for (size_t i = last_seen_idx; i < numsSize; i++) {
        if (nums[i] == last_seen_val) {
            if ((i - last_seen_idx) >= 2) {
                continue;   
            }
        } else {
            last_seen_val = nums[i];
            last_seen_idx = i;
        }
        nums[copy_index++] = nums[i];
    }


    return copy_index; 
}

/* 
Example 1:
    Input: nums = [1,1,1,2,2,3]
    Output: 5, nums = [1,1,2,2,3,_]
    Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:
    Input: nums = [0,0,1,1,1,1,2,3,3]
    Output: 7, nums = [0,0,1,1,2,3,3,_,_]
    Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores). */

int main() {
    int nums[] = {1,1,1,2,2,3};
    int k;

    k = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", k);
    int nums2[] = {0,0,1,1,1,1,2,3,3};
    k = removeDuplicates(nums2, sizeof(nums2) / sizeof(nums2[0]));
    printf("%d\n", k);

    return 0;
}
