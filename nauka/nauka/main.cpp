#include <iostream>
#include <string>
#include <cassert>


void swapByRef(int& a, int&b)
{
	int bufor = a;
	a = b;
	b = bufor;
}

void findMinMax(const int arr[], int size, int& outMin, int& outMax)
{
	outMax = arr[0];
	outMin = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > outMax) { outMax = arr[i]; }
		if (arr[i] < outMin) { outMin = arr[i]; }
	}
}


int main()
{


}