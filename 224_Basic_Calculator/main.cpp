#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <stack>


using namespace std;


int isoper(char c) {
    switch (c) {
        case '*':
        case '/':
        case '+':
        case '-':
            return true;
    }
    return false;
}

int isoper(string& s) {
    return isoper(s[0]);
}

int my_eval(int v1, int v2, char oper) {
    switch (oper) {
        case '*': return v1 * v2;
        case '/': return v1 / v2;
        case '+': return v1 + v2;
        case '-': return v1 - v2;
        default:
            throw runtime_error("Unknown operator");
    }
}

int get_precedence(char op) {
    switch (op) {
        /* Precedence defined according to cppref */
        case '*':
        case '/': return 5;
        case '+':
        case '-': return 6;
        case '(':
        case ')': return 1;
        default:
            throw runtime_error("Unknown operator");
    }
}

int is_stack_op_high_precedence(char new_op, char stack_op) {
    int new_op_pre   = get_precedence(new_op);
    int stack_op_pre = get_precedence(stack_op);
    if (new_op_pre >= stack_op_pre)
        return true;
    return false;
}

int eval(stack<string>& output) {
    string op = output.top(); output.pop();

    int val2, val1;
    if (isoper(output.top())) {
        val2 = eval(output);
    } else {
        val2 = stoi(output.top());
        output.pop();
    }
    if (isoper(output.top())) {
        val1 = eval(output);
    } else {
        val1 = stoi(output.top());
        output.pop();
    }

    return my_eval(val1, val2, op[0]);
}

enum Operations {
    Operand,
    Operator,
    OpenBrackets,
    Unknown,
};

int calculate(string s) {
    stack<string> output;
    stack<char>   oper;

    Operations last_oper = Unknown;
    for (size_t i = 0; i < s.size(); ) {
        if (s[i] == ' ') {
            i++;
            continue;
        }

        if (s[i] == '(') {
            oper.push(s[i]);
            i++;
            last_oper = OpenBrackets;
        }
        if (s[i] == ')') {
            char curr_oper;
            while ((curr_oper = oper.top()) != '(') {
                string str(1, curr_oper);
                output.push(str);
                oper.pop();
            }
            oper.pop(); // pop '(' from oper stack
            i++;
        }

        if (isdigit(s[i])) {
            size_t j = 0;
            while (isdigit(s[i])) {
                i++;
                j++;
            }
            output.push(s.substr(i - j, j));
            last_oper = Operand;
        }

        if (isoper(s[i])) {
            char new_op = s[i];

            while (!oper.empty() && (oper.top() != '(')) {
                char stack_op = oper.top();
                if (is_stack_op_high_precedence(new_op, stack_op)) {
                    string str(1, stack_op);
                    output.push(str);
                    oper.pop();
                } else {
                    break;
                }
            }
            if (last_oper == Operator || last_oper == OpenBrackets) {
                if (new_op == '-' || new_op == '+')
                    output.push("0");
            }
            oper.push(new_op);
            i++;
            last_oper = Operator;
        }
    }

    while (!oper.empty()) {
        string str(1, oper.top());
        output.push(str);
        oper.pop();
    }

    if (output.size() == 1)
        return stoi(output.top());

    return eval(output);
}


void runTest(string s, int result) {
    int ret = calculate(s);
    if (ret != result) {
        std::ostringstream oss;
        oss << "ERR! calculate(" << s << ")" << " != " << result;
        throw std::runtime_error(oss.str());
    }
    cout << "OK! calculate(" << s << ")" << " == " << ret << endl;
}

int main() {
    try {
        runTest("1+2*3-4", 3);
        runTest("1+(2+3)+4", 10);
        runTest("1 + 1", 2);
        runTest("2-1 + 2", 3);
        runTest("(1+(4+5+2)-3)+(6+8)", 23);
        runTest("0", 0);
        runTest("1", 1);
        runTest("1-(      -2 )", 3);
    } catch (overflow_error const& e) {
        cout << e.what() << '\n';
    h

    return 0;
}
