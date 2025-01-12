#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <cstdint>

using namespace std;




bool wordBreak(string s, size_t s_idx, vector<string>& wordDict, map<uint32_t, bool>& visited) {

    if (s_idx == s.size())
        return true;
    if (s_idx > s.size())
        return false;
    
    int ret;
    for (size_t i = 0; i < wordDict.size(); i++) {
        uint32_t key = s_idx << 16 | i;
        if (visited[key] == true)
            continue;
        ret = s.compare(s_idx, wordDict[i].size(), wordDict[i]);
        visited[key] = true;
        if (ret == 0) {
            bool found = wordBreak(s, s_idx + wordDict[i].size(), wordDict, visited);
            if (found) {
                return found;
            } else {
                continue;
            }
        }
    }

    return false;
}


bool wordBreak(string s, vector<string>& wordDict) {
    map <uint32_t, bool> visited;
    size_t s_idx;
    s_idx = 0;

    return wordBreak(s, s_idx, wordDict, visited);
}


/* Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false  */
int main() {
    vector<string> wordDict[] = {
        {"leet", "code"},
        {"apple", "pen"},
        {"cats","dog","sand","and","cat"},
        {"car","ca","rs"},
        {"cats","dog","sand","and","cat","an"},
        {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"},
    };
    bool ret;

    ret = wordBreak("leetcode", wordDict[0]);
    cout << ret << endl;
    ret = wordBreak("applepenapple", wordDict[1]);
    cout << ret << endl;
    ret = wordBreak("catsandog", wordDict[2]);
    cout << ret << endl;
    ret = wordBreak("cars", wordDict[3]); // expected true
    cout << ret << endl;
    ret = wordBreak("catsandogcat", wordDict[4]); // expected true
    cout << ret << endl;
    ret = wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
, wordDict[5]); // expected true
    cout << ret << endl;

    return 0;
}
