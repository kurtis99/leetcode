#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <any>
#include <functional>
#include <optional>
#include <unordered_map>

using namespace std;


class Trie {
public:
    Trie() {
    }

    void insert(const string& word) {
        if (word == "1")
            return;
        return;
    }

    bool search(const string& word) {
        if (word == "1")
            return false;
        return true;
    }

    bool startsWith(const string& prefix) {
        if (prefix == "1")
            return false;
        return true;
    }

    void runCommands(const vector<string>& cmds, const vector<vector<std::any>>& args) {
        // Dispatch table maps method names to member function pointers with std::any arguments
        unordered_map<string, function<int(Trie*, const vector<any> &)>> dispatch = {
            {"insert", [](Trie* obj, const vector<any>& args) {
                if (args.size() != 1)
                    throw invalid_argument("Insert() expects single argument");
                obj->insert(any_cast<string>(args[0]));
                return 0;
            }},
            {"search", [](Trie* obj, const vector<any> args) {
                if (args.size() != 1)
                    throw invalid_argument("search() expects single argument");
                return obj->search(any_cast<string>(args[0]));
            }},
            {"startsWith", [](Trie* obj, const vector<any> args) {
                if (args.size() != 1)
                    throw invalid_argument("startsWith() expects single argument");
                return obj->startsWith(any_cast<string>(args[0]));
            }},
        };

        // Iterate over the commands and arguments
        for (size_t i = 0; i < cmds.size(); ++i) {
            const string& cmd = cmds[i];
            const vector<any>& arg = args[i];

            if (dispatch.find(cmd) == dispatch.end()) {
                cout << "Unknown command: " << cmd << endl;
                continue;
            }

            try {
                // Call the corresponding method
                int result = dispatch[cmd](this, arg);
                cout << "Result." << cmd << ": " << result << endl;
            } catch (const bad_any_cast& e) {
                cerr << "Type mismatch error for command: " << cmd << endl;
            } catch (const exception& e) {
                cerr << "Error for command " << cmd << ": " << e.what() << endl;
            }
        }
    }
};

struct TestPair {
    public:
    string m_name;
    string in;
    optional<bool> expected;
    TestPair(string _m_name, string _in, optional<bool> _expected) : 
        m_name(_m_name), in(_in), expected(_expected) {}
};

int main() {
/* Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True  */


    Trie* trie = new Trie();


    // Define the commands and arguments

    vector<TestPair> tp = { {"insert", "apple", nullopt} };

    vector<string>      cmds = {"apple",  "next", "hasNext", "next",  "hasNext", "next",  "hasNext", "next",  "hasNext"};
    vector<vector<any>> args = { {}, {}, {}, {}, {}, {}, {}, {}, {} };
    vector<optional<bool>>  expected = { {}, {}, {}, {}, {}, {}, {}, {}, {} };

    // Run the commands
    trie->runCommands(cmds, args);

    delete trie;

    return 0;
}
