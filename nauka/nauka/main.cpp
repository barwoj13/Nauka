#include <iostream>
#include <string>
#include <cassert>

int* filterEven(const int* arr, int size, int& newSize)
{
	int parzyste = 0;
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] % 2 == 0) parzyste++;
	}

	//std::cout << parzyste;

	int* T = new int[parzyste] {};

	int bufor = 0;

	for (int i = 0; i < size; i++) 
	{
		if (arr[i] % 2 == 0) 
		{
			T[bufor] = arr[i];
			bufor++;
		}
	}
	newSize = parzyste;
	return T;
}

int main()
{
	int size = 4;
	int newSize = 0;
	
	int* arr = new int[size] {2, 2, 1, 4};

	int* test = filterEven(arr, size, newSize);

	for (int i = 0; i < newSize; i++) 
	{
		std::cout << test[i] << " ";
	}
	delete[] arr;
	delete[] test;
}