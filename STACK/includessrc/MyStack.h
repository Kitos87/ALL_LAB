#include<iostream>
#include<stdexcept>
using namespace std;

template <class T>
class TStack {
protected:
    int size;
    int top;
    T* mas;
public:
    TStack(int size = 1) {
        if (size <= 0) throw invalid_argument("Size must be greater than 0");
        this->size = size;
        this->top = 0;
        this->mas = new T[size]();
        if (this->mas == nullptr) throw bad_alloc();
    }
    TStack(const TStack<T>& stack) {
        if (stack.size <= 0) throw invalid_argument("Size of the stack to be copied is <= 0");
        this->size = stack.size;
        this->top = stack.top;
        this->mas = new T[size];
        if (this->mas == nullptr) throw bad_alloc();
        for (int i = 0; i < top; i++) {
            this->mas[i] = stack.mas[i];
        }
    }
    ~TStack() {
        delete[] mas;
    }
    void Push(T a) {
        if (IsFull()) throw overflow_error("Stack is full");
        mas[top++] = a;
    }
    T Pop() {
        if (IsEmpty()) throw underflow_error("Stack is empty");
        return mas[--top]; 
    }
    T Top() const {
        if (IsEmpty()) throw underflow_error("Stack is empty");
        return mas[top - 1]; 
    }
    int GetSize() const {
        return size;
    }
    int GetTop() const {
        return top;
    }
    bool IsFull() const {
        return top == size;
    }
    bool IsEmpty() const {
        return top == 0;
    }
    void Clear() {
        for (int i = 0; i < top; ++i) {
            mas[i] = T(); 
        }
        top = 0;
    }
    TStack& operator=(const TStack<T>& stack) {
        if (this == &stack) return *this;
        if (this->size != stack.size) {
            T* newMas = new T[stack.size];
            if (newMas == nullptr) throw bad_alloc();
            delete[] this->mas;
            this->mas = newMas;
            this->size = stack.size;
        }
        this->top = stack.top;
        for (int i = 0; i < top; i++) {
            this->mas[i] = stack.mas[i];
        }
        return *this;
    }
};

