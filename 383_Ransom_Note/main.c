#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
Example 1:
    Input: ransomNote = "a", magazine = "b"
    Output: false
Example 2:
    Input: ransomNote = "aa", magazine = "ab"
    Output: false
Example 3:
    Input: ransomNote = "aa", magazine = "aab"
    Output: true */

bool canConstruct(char* ransomNote, char* magazine) {
    // Construct magazine dictionary
    int dict[32];
    memset(dict, 0, 32);
    size_t i = 0;
    while (magazine[i] != '\0') {
        int c = magazine[i] - 'a';
        dict[c]++;
        i++;
    }
    // not try to check dict if it can be used to construct note
    i = 0;
    while (ransomNote[i] != '\0') {
        int c = ransomNote[i] - 'a';
        if (dict[c] == 0) {
            // Ransom note can not be constructed
            return false;
        }
        dict[c]--;
        i++;
    }

    return true;
}

int main() {

    {
        char* note = "a";
        char* maga = "b";
        int ret;
        ret = canConstruct(note, maga);
        printf("Can be constructed: %d (expect false)\n", ret);
    }
    {
        char* note = "aa";
        char* maga = "ab";
        int ret;
        ret = canConstruct(note, maga);
        printf("Can be constructed: %d (expect false)\n", ret);
    }
    {
        char* note = "aa";
        char* maga = "aab";
        int ret;
        ret = canConstruct(note, maga);
        printf("Can be constructed: %d (expect true)\n", ret);
    }
    
}
