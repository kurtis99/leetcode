#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {

    int lo, hi, step;
    lo = 0;
    hi = numsSize - 1;

    while (lo <= hi) {
        step = (hi + lo) / 2;
        if (target > nums[step]) {
            lo = step + 1;
        } else if (target < nums[step]) {
            hi = step - 1;
        } else {
            return step;
        }
    }

    return lo;
}

int main() {

    int ret;

    int arr[] = {1,3,5,6};
    ret = searchInsert(arr, 4, 5);
    printf("%d\n", ret);
    ret = searchInsert(arr, 4, 2);
    printf("%d\n", ret);
    ret = searchInsert(arr, 4, 7);
    printf("%d\n", ret);

    return 0;
}
