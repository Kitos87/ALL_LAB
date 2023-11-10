#include<iostream>
using namespace std;

template <class T>
class TQueue {
protected:
    int size;
    int start;
    int end;
    int count;
    T* mas;

public:
    TQueue(int _size = 1) {
        if (_size <= 0) {
            throw "Invalid size"; // Исключение для некорректного размера
        }
        size = _size;
        start = 0;
        end = 0;
        count = 0;
        mas = new T[size]();
    }

    TQueue(const TQueue <T>& q) {
        size = q.size;
        start = q.start;
        end = q.end;
        count = q.count;

        mas = new T[size];
        for (int i = 0; i < count; ++i) {
            mas[(start + i) % size] = q.mas[(q.start + i) % size];
        }
    }

    ~TQueue() {
        delete[] mas;
    }

    void Push(T a) {
        if (IsFull()) {
            throw "Queue is full"; // Исключение для полной очереди
        }
        mas[end] = a;
        end = (end + 1) % size; // Правильно обновляем end
        count++;
    }

    T Get() {
        if (IsEmpty()) {
            throw "Queue is empty"; // Исключение для пустой очереди
        }
        T result = mas[start];
        start = (start + 1) % size; // Правильно обновляем start
        count--;
        return result;
    }

    int GetSize() const {
        return size;
    }

    bool IsFull() const {
        return count == size;
    }

    bool IsEmpty() const {
        return count == 0;
    }

    TQueue& operator=(const TQueue& q) {
        if (this != &q) {
            delete[] mas;
            size = q.size;
            start = q.start;
            end = q.end;
            count = q.count;
            mas = new T[size];
            for (int i = 0; i < count; ++i) {
                mas[(start + i) % size] = q.mas[(q.start + i) % size];
            }
        }
        return *this;
    }
};
