#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"../STACK/includessrc/MyStack.h"
using namespace std;

class TArithmeticExpression {
    string infix;
    string postfix;
    map<char, int> priority;
    TStack<char> st;
    TStack<double> st2;

public:
    TArithmeticExpression(string infx) :
        infix(infx),
        st(infx.length()), // Инициализация стека символов с размером входной строки
        st2(infx.length()) { // Инициализация стека чисел, размер можно скорректировать
        priority = { {'(', 1},{')', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}};
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
            postfix += " ";
            if (src[i] >= '0' && src[i] <= '9' || src[i] == '.') {
                postfix += src[i];
            }
            else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/') {
                elem = st.Pop();
                while (priority[elem] >= priority[src[i]]) {
                    postfix += elem;
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
                    elem = st.Pop();
                }
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
            i++;
        }
        return st2.Top();
    }
};
