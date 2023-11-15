#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"../STACK/includessrc/MyStack.h"
using namespace std;
#define M_PI 3.14159265358979323846

class TArithmeticExpression {
    string infix;
    string postfix;
    map<char, int> priority;
    TStack<char> st;
    TStack<double> st2;

public:
    TArithmeticExpression(string infx) : infix(infx), st(infx.length()), st2(infx.length()) { 
        priority = { {'(', 1},{')', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'s', 4}, {'c', 4}, {'r', 4},{'^', 5}};
        ToPostfix();
    }
    string GetInfix() const {
        return infix;
    }
    string GetPostfix() const {
        return postfix;
    }
    void ToPostfix() {
        st.Clear();
        postfix = "";
        string src = "(" + infix + ")";
        char elem;
        unsigned int i = 0;
        while (i < src.size()) {
            if (src[i] >= '0' && src[i] <= '9' || src[i] == '.') {
                while (src[i] >= '0' && src[i] <= '9' || src[i] == '.') {
                    postfix += src[i++];
                }
                postfix += " ";
                continue;
            }
            else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i] == '^') {
                elem = st.Pop();
                while (priority[elem] >= priority[src[i]]) {
                    postfix += elem;
                    postfix += " ";
                    elem = st.Pop();
                }
                st.Push(elem);
                st.Push(src[i]);
            }
            else if (src[i] == '(') {
                st.Push(src[i]);
            }
            else if (src[i] == ')') {
                elem = st.Pop();
                while (elem != '(') {
                    postfix += elem;
                    postfix += " ";
                    elem = st.Pop();
                }
            }
            else if (src[i] == 's') { 
                st.Push('s'); 
                i += 2; 
            }
            else if (src[i] == 'c') { 
                st.Push('c'); 
                i += 2; 
            }
            else if (src[i] == 'r') {
                st.Push(src[i]);
            }
            i++;
        }
    }
    double Calculate() {
        st2.Clear();
        unsigned int i = 0;
        while (i < postfix.size()) {
            if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
                double k2 = st2.Pop();
                double k1 = st2.Pop();
                switch (postfix[i]) {
                case '+':
                    st2.Push(k1 + k2);
                    break;
                case '-':
                    st2.Push(k1 - k2);
                    break;
                case '*':
                    st2.Push(k1 * k2);
                    break;
                case '/':
                    if (k2 == 0) throw runtime_error("Division by zero");
                    st2.Push(k1 / k2);
                    break;
                }
            }
            else if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
                size_t idx;
                double tmp = stod(&postfix[i], &idx);
                st2.Push(tmp);
                i += idx - 1;
            }
            else if (postfix[i] == 's') { 
                double value = st2.Pop();
                value = value * M_PI / 180.0;
                st2.Push(sin(value));
                i++;
            }
            else if (postfix[i] == 'c') { 
                double value = st2.Pop();
                value = value * M_PI / 180.0;
                st2.Push(cos(value));
                i++; 
            }
            else if (postfix[i] == 'r') {
                double value = st2.Pop();
                st2.Push(sqrt(value));
                i++;
            }
            else if (postfix[i] == '^') {
                double exponent = st2.Pop();
                double base = st2.Pop();
                st2.Push(pow(base, exponent)); 
                i++;
            }
            i++;
        }
        return st2.Top();
    }
};
