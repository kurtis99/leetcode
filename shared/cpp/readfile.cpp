#include "readfile.hpp"

using namespace std;


vector<pair<vector<int>, vector<int>>> parseFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Failed to open file");
    }
    
    vector<pair<vector<int>, vector<int>>> results;
    string line;
    
    while (getline(file, line)) {
        istringstream ss(line);
        char ch;
        ss >> ch; // Read '['
        if (ch != '[') {
            throw runtime_error("Invalid format: missing opening bracket");
        }
        
        vector<int> vec;
        vector<int> args;
        int num;
        while (ss >> num) {
            vec.push_back(num);
            if (ss.peek() == ',') ss.ignore();
        }
        
        ss.clear(); // Clear EOF state
        ss >> ch; // Read ']'
        if (ch != ']') {
            throw runtime_error("Invalid format: missing closing bracket");
        }
        
        // Read additional arguments if present
        while (ss >> num) {
            args.push_back(num);
        }
        
        results.emplace_back(vec, args);
    }
    
    return results;
}
