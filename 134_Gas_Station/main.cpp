#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>

using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    size_t stations = gas.size();
    size_t gas_total  = 0;
    size_t cost_total = 0;
    int start_pos = 0;
    int total = 0;
    for (size_t i = 0; i < stations; i++) {
        gas_total  += gas[i];
        cost_total += cost[i];

        total += gas[i] - cost[i];
        if (total < 0) {
            total = 0;
            start_pos = i + 1;
        }
    }
    if (gas_total < cost_total)
        return -1;

    return start_pos;
}

void runTest(vector<int> gas, vector<int> cost, int expected) {
    int result = canCompleteCircuit(gas, cost);
    if (result != expected) {
        std::ostringstream oss;
        oss << "ERR! expected " << expected << " actual " << result;
        throw std::runtime_error(oss.str());
    }
    cout << "OK!" << endl;
}

int main() {

    try {
        runTest({1,2,3,4,5}, {3,4,5,1,2}, 3);
        runTest({5,1,2,3,4}, {4,4,1,5,1}, 4);
        runTest({4,5,2,6,5,3}, {3,2,7,3,2,9}, -1);
        runTest({2,3,4}, {3,4,3}, -1);

        vector<int>  gas_1(100000, 1);
        vector<int> cost_1(100000, 1);
        cost_1[50000] = 2;
        runTest(gas_1, cost_1, -1);
        runTest({2}, {2}, 0);

    } catch (overflow_error const& e) {
        cout << e.what() << '\n';
    }

    return 0;
}
