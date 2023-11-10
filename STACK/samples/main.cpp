#include <iostream>
#include"MyStack.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    /*try {
        TStack<int> stack(3);
        cout << "Создан стек с размером 3" << endl;
        cout << "Добавляем элементы 11, 22, 33" << endl;
        stack.Push(11);
        stack.Push(22);
        stack.Push(33);
        cout << "Верхний элемент стека: " << stack.TopView() << endl;
        cout << "Извлекаем элемент -> " << stack.Get() << endl;
        cout << "Извлекаем еще один элемент -> " << stack.Get() << endl;
        cout << "Теперь верхний элемент стека -> " << stack.TopView() << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }*/


    int size;
    cout << "Enter the initial size of the stack: ";
    cin >> size;

    // Проверка корректности ввода размера стека
    while (size <= 0) {
        cout << "Size must be greater than 0. Please enter again: ";
        cin >> size;
    }

    TStack<int> stack(size);
    int choice;
    int value;

    while (true) {
        system("cls");
        cout << "Menu:" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. View top element" << endl;
        cout << "4. Check stack size and number of elements" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            try {
                stack.Push(value);
                cout << "Value pushed successfully!" << endl;
            }
            catch (const exception& e) {
                cout << "Exception: " << e.what() << endl;
            }
            system("pause");
            break;

        case 2:
            try {
                value = stack.Pop();
                cout << "Popped value: " << value << endl;
            }
            catch (const exception& e) {
                cout << "Exception: " << e.what() << endl;
            }
            system("pause");
            break;

        case 3:
            try {
                cout << "Top element: " << stack.Top() << endl;
            }
            catch (const exception& e) {
                cout << "Exception: " << e.what() << endl;
            }
            system("pause");
            break;

        case 4:
            cout << "Current stack size: " << stack.GetSize() << endl;
            cout << "Current number of elements: " << stack.GetTop() << endl;
            system("pause");
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please select again." << endl;
            system("pause");
            break;
        }
    }
	return 0;
}
