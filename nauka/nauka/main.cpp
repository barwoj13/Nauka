#include <iostream>
#include <string>
#include <cassert>


void swapByRef(int& a, int&b)
{
	int bufor = a;
	a = b;
	b = bufor;
}

void swapByPtr(int* a, int* b)
{
	if (a == nullptr || b == nullptr) return;
	int bufor = *a;
	*a = *b;
	*b = bufor;
}

int main()
{
	int a = 3;
	int b = 8;

	std::cout << "a: " << a << ", b: " << b << std::endl;

	swapByRef(a, b);

	std::cout << "a: " << a << ", b: " << b << std::endl;

	swapByPtr(&a, &b);

	std::cout << "a: " << a << ", b: " << b << std::endl;


}