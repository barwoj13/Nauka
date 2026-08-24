#include <iostream>
#include <string>
#include <cassert>

void reverseArray(int* start, int* end)
{
	if (start == nullptr || end == nullptr) return;

	while(start < end) // Bezpieczniejsze ni¿ start != end bo gdyby by³a to tablica parzysta to wskaŸniki by siê wyminê³y
	{
		int bufor = *start;
		*start = *end;
		*end = bufor;
		start++;
		end--;
	}
}

int main()
{
	int tab[] = { 1, 2, 3, 4 };
	int size = 4;

	reverseArray(tab, tab + size - 1);

	for(int i = 0; i < size; i++)
	{
		std::cout << tab[i] << " ";
	}
}