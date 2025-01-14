#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <any>
#include <functional>

#include "binary_tree.hpp"

using namespace std;


class BSTIterator {
    TreeNode* root = NULL;
    int curr_ptr;
public:
    BSTIterator(TreeNode* _root) {
        root = _root;
        curr_ptr = -1;
    }

    int search_next(TreeNode* curr_root, int a, int possible_next) {
        TreeNode* next_root = curr_root->right;
        if (a < curr_root->val) {
            possible_next = curr_root->val;
            next_root     = curr_root->left;
        }
        if (next_root == nullptr)
            return possible_next >= curr_root->val ? possible_next : curr_root->val;
        return search_next(next_root, a, possible_next);
    }

    int next() {
        TreeNode* tmp = root;
        curr_ptr = search_next(tmp, curr_ptr, curr_ptr);
        return curr_ptr;
    }

    bool hasNext() {
        TreeNode* tmp = root;
        int old_curr_ptr = curr_ptr;
        int new_curr_ptr = 0;
        new_curr_ptr = search_next(tmp, curr_ptr, curr_ptr);
        return new_curr_ptr != old_curr_ptr;
    }

    void runCommands(const vector<string>& cmds, const vector<vector<std::any>>& args) {
        // Dispatch table maps method names to member function pointers with std::any arguments
        unordered_map<string, function<int(BSTIterator*, const vector<any>&)>> dispatch = {
            {"next", [](BSTIterator* obj, const vector<any>& args) {
                if (args.size() != 0)
                    throw invalid_argument("next() does not expect any arguments");
                return obj->next();
            }},
            {"hasNext", [](BSTIterator* obj, const vector<any>& args) {
                if (args.size() != 0)
                    throw invalid_argument("hasNext() does not expect any arguments");
                return obj->hasNext();
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


/* 
 * ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
 * [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
 * */
int main() {

    vector<optional<int>> arr = {7, 3, 15, nullopt, nullopt, 9, 20};
    TreeNode* root = createTree(arr, 0); 

    BSTIterator obj(root);

    // Define the commands and arguments
    vector<string>      cmds = {"next",  "next", "hasNext", "next",  "hasNext", "next",  "hasNext", "next",  "hasNext"};
    vector<vector<any>> args = { {}, {}, {}, {}, {}, {}, {}, {}, {} };

    // Run the commands
    obj.runCommands(cmds, args);

    destroyTree(root);

    return 0;
}
