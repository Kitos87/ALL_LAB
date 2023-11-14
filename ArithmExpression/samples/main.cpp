#include<iostream>
#include<string>
#include"MyArithmExpress.h" 

using namespace std;

int main() {
    cout << "Infix expression: " << endl;
    string expr = "(4+11-8/2*(7*3+4-7))*3";
    cout << expr << endl;

    try {
        TArithmeticExpression calc(expr); 

        cout << "Postfix expression: " << endl;
        cout << calc.GetPostfix() << endl;

        cout << "Calculated result: " << endl;
        cout << calc.Calculate() << endl; 
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
