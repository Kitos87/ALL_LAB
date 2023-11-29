#include<iostream>
using namespace std;

template <class T>
class TQueue
{
protected:
	T* mas;
	int head, tail;
	int count_elem;
	int max_size;

public:
	TQueue(int size = 10) {
		if (size < 0)
			throw invalid_argument("Size must be greater than 0");
		max_size = size;
		mas = new T[max_size];
		head = 0;
		tail = -1;
		count_elem = 0;
	}

	TQueue(const TQueue <T>& q) {
		max_size = q.max_size;
		head = q.head;
		tail = q.tail;
		count_elem = q.count_elem;
		mas = new T[size];
		for (int i = 0; i < count; ++i) {
		    mas[(head + i) % max_size] = q.mas[(q.head + i) % max_size];
		}
	}

	~TQueue() {
		delete[] mas;
	}

	bool IsEmpty() {
		return count_elem == 0;
	}

	bool IsFull() {
		return count_elem == max_size;
	}

	void Push(T el) {
		tail = (tail + 1) % max_size;
		if (!IsFull()) {
			mas[tail] = el;
			count_elem++;
		}
		else
			throw "Queue is full";
	}

	T Pop() {
		if (!IsEmpty()) {
			T res = mas[head];
			head = (head + 1) % max_size;
			count_elem--;
			return res;
		}
		else
			throw "Queue is empty";
	}

	int GetHead() {
		return head;
	}

	int GetMaxSize() {
		return max_size;
	}

	int GetSize() {
		return count_elem;
	}

	TQueue& operator=(const TQueue& q) {
		if (this != &q) {
		    delete[] mas;
		    max_size = q.max_size;
		    head = q.head;
		    tail = q.tail;
		    count_elem = q.count_elem;
		    mas = new T[size];
		    for (int i = 0; i < count_elem; ++i) {
		        mas[(head + i) % max_size] = q.mas[(q.head + i) % max_size];
		    }
		}
		return *this;
	}

};
