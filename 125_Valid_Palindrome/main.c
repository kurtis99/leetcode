#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

static int get_first_valid_char(int *search_idx, int inc, const char* s) {
    do {
        char curr_char = s[*search_idx];
        if (isalnum(curr_char))
            return tolower(s[*search_idx]);
        *search_idx += inc;
    } while ((*search_idx >= 0) && (*search_idx < strlen(s)));
    return '\0';
}

bool isPalindrome(char* s) {
    int s_len = strlen(s);
    int lo_idx = 0;
    int hi_idx = s_len - 1;
    while (lo_idx < hi_idx) {
        char lo = get_first_valid_char(&lo_idx,  1, s);
        char hi = get_first_valid_char(&hi_idx, -1, s);
        if (lo != hi)
            return false;
        lo_idx++;
        hi_idx--;
    }

    return true;
}

/* 
 * Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
 * */
int main() {

    int ret;
    char *str1 = "A man, a plan, a canal: Panama";
    char *str2 = "race a car";
    char *str3 = "a.";

    ret = isPalindrome(str1);
    printf("%s : %d\n", str1, ret);
    ret = isPalindrome(str2);
    printf("%s : %d\n", str2, ret);
    ret = isPalindrome(str3);
    printf("%s : %d\n", str3, ret);

    return 0;
}
