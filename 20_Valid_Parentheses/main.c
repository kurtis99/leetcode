#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


/*
Example 1:
    Input: s = "()"
    Output: true
Example 2:
    Input: s = "()[]{}"
    Output: true
Example 3:
    Input: s = "(]"
    Output: false
Example 4:
    Input: s = "([])"
    Output: true */

char *stack = NULL;
size_t free_index = 0;

bool stack_empty() {
    return free_index == 0;
}

char pop() {
    if (stack_empty()) return '\0';
    return stack[free_index--];
}

char peek() {
    return stack[free_index - 1];
}

void push(char c) {
    stack[free_index++] = c;
}


bool is_match_br(char open_br, char close_br) {
    if (open_br == '(') return close_br == ')';
    if (open_br == '[') return close_br == ']';
    if (open_br == '{') return close_br == '}';
    return false;
}

bool isValid(char* s) {
    size_t s_len = strlen(s);
    stack = malloc(sizeof(char) * s_len);
    free_index = 0;

    bool ret = true;
    char c;
    size_t i = 0;
    while ((c = s[i++]) != '\0')  {
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        }
        if (c == ')' || c == ']' || c == '}') {
            if (stack_empty()) {
                ret = false;
                goto do_exit;
            }
            char stack_c = peek();
            if (is_match_br(stack_c, c))
                pop();
            else {
                ret = false;
                goto do_exit;
            }
                           
        }
    }

    if (!stack_empty())
        ret = false;

do_exit:
    free(stack);
    return ret;
}

int main() {
    {
        char* s = "()";
        printf("%s - %d\n", s, isValid(s));
    }
    {
        char* s = "()[]{}";
        printf("%s - %d\n", s, isValid(s));
    }
    {
        char* s = "([])";
        printf("%s - %d\n", s, isValid(s));
    }
    {
        char* s = "([)]";
        printf("%s - %d\n", s, isValid(s));
    }
    {
        char* s = "(";
        printf("%s - %d\n", s, isValid(s));
    }
    {
        char* s = ")";
        printf("%s - %d\n", s, isValid(s));
    }
}
