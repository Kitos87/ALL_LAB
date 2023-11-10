#include<iostream>
#include<string>
#include"MyArithmExpress.h" // Убедитесь, что путь к заголовочному файлу правильный

using namespace std;

int main() {
    cout << "Infix expression: " << endl;
    string expr = "(4+11-8/2*(7*3+4-7))*3";
    cout << expr << endl;

    try {
        TArithmeticExpression calc(expr); // Создание объекта для вычисления арифметического выражения

        cout << "Postfix expression: " << endl;
        cout << calc.GetPostfix() << endl; // Вывод постфиксного выражения

        cout << "Calculated result: " << endl;
        cout << calc.Calculate() << endl; // Вывод результата вычисления выражения
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
