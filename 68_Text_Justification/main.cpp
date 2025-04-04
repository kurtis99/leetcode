#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <list>

using namespace std;


string comb(list<string>& words, int maxWidth, bool last_line) {
    int num_of_words   = words.size();
    int space_interval = num_of_words - 1;

    int words_size = 0;
    for (auto w : words) words_size += w.size();

    if (space_interval == 0) {
        string ret;
        ret += words.back(); words.pop_back();
        int spaces_to_fit = maxWidth - words_size;
        while (spaces_to_fit--) ret += " ";
        return ret;
    }

    // we have combined size of all words to be printed in string
    // now need to calculate number of spaces to be added
    int spaces = maxWidth - words_size;
    int spaces_per_int = spaces / space_interval;
    int left_spaces    = spaces % space_interval;

    string ret;

    if (last_line) {
        left_spaces = 0;
        spaces_per_int = 1;
    }

    ret += words.front(); words.pop_front();
    while (words.size() > 0) {
        if (left_spaces-- > 0) ret += " ";
        for (int i = 0; i < spaces_per_int; i++) ret += " ";
        ret += words.front(); words.pop_front();
    }

    if (last_line) {
        int spaces_to_fit = maxWidth - ret.size();
        while (spaces_to_fit--) ret += " ";
    }

    return ret;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;

    int curr_line_len = 0;
    int add_line_len = 0;
    list<string> words_in_line;
    for (auto word : words) {
        add_line_len = curr_line_len ? (word.size() + 1) : word.size();

        if (curr_line_len + add_line_len > maxWidth) {
            string r;
            r = comb(words_in_line, maxWidth, false);
            ret.push_back(r);
            curr_line_len = word.size();
        } else {
            curr_line_len += add_line_len;
        }
        words_in_line.push_back(word);
    }

    if (words_in_line.size()) {
        string r = comb(words_in_line, maxWidth, true);
        ret.push_back(r);
    }

    return ret;
}


void runTest(vector<string> words, int maxWidth) {
    vector<string> ret;
    cout << "------------------------------------------" << endl;
    ret = fullJustify(words, maxWidth);
    for (auto s : ret) cout << s << endl;
    cout << "------------------------------------------" << endl;
}


int main() {

    runTest( {"This", "is", "an", "example", "of", "text", "justification."}, 16 );
    runTest( {"What","must","be","acknowledgment","shall","be"}, 16);
    runTest( {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}, 20);

    return 0;
}
