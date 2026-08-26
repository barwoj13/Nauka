#include <iostream>
#include <string>

class intStack
{
private:
	int* data;
	size_t capacity;
	int topIndex; // ustawiamy na -1 gdy stos jest pusty

public:
	intStack(size_t cap = 10)
		: capacity(cap), topIndex(-1)
	{
		data = new int[cap] {};
	}

	~intStack() 
	{
		delete[] data;
	}

	intStack(const intStack& other) 
	{
		capacity = other.capacity;
		topIndex = other.topIndex;
		data = new int[capacity];

		for (int i = 0; i < capacity; i++) 
		{
			data[i] = other.data[i];
		}
	}

	intStack& operator=(const intStack& other)
	{
		if (this == &other) return *this;
		delete[] data;

		capacity = other.capacity;
		topIndex = other.topIndex;
		data = new int[capacity];

		for (int i = 0; i < capacity; i++)
		{
			data[i] = other.data[i];
		}

		return *this;
	}

	void push(int val) 
	{
		if (topIndex + 1 >= capacity) return;

		topIndex++;
		data[topIndex] = val;
	}

	void pop() 
	{
		if (topIndex == -1) return;
		topIndex--;
	}

	int top() const 
	{
		return data[topIndex];
	}

	bool isEmpty() const 
	{
		return topIndex == -1;
	}
};

int main()
{
	intStack s1(5);
	s1.push(10);
	s1.push(20);
	s1.push(30);

	// Test konstruktora kopiuj¹cego
	intStack s2 = s1;

	std::cout << "Top s1: " << s1.top() << std::endl; // 30
	std::cout << "Top s2: " << s2.top() << std::endl; // 30

	s1.pop();
	std::cout << "Po pop() na s1:" << std::endl;
	std::cout << "Top s1: " << s1.top() << std::endl; // 20
	std::cout << "Top s2: " << s2.top() << std::endl; // 30 (s2 ma w³asn¹ kopiê pamiêci!)
}