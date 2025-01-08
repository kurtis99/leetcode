#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int curr = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[curr] = nums[i];
            curr++;
        }
    }
    return curr;
}

int main() {

    int ret;

    int arr1[] = {3,2,2,3};
    int arr2[] = {0,1,2,2,3,0,4,2};
    int arr3[] = {4,5};
    int arr4[] = {0,4,4,0,4,4,4,0,2};
    int arr5[] = {3,3};

    ret = removeElement(arr1, 4, 3);
    printf("%d\n", ret);
    ret = removeElement(arr2, 8, 2);
    printf("%d\n", ret);
    ret = removeElement(arr3, 2, 5);
    printf("%d\n", ret);
    ret = removeElement(arr4, 9, 4);
    printf("%d\n", ret);
    ret = removeElement(arr5, 2, 3);
    printf("%d\n", ret);

    return 0;
}
