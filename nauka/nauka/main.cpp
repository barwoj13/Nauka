#include <iostream>
#include <string>
#include <cassert>

size_t myStrLen(const char* str) 
{
	size_t rozmiar = 0;
	
	while (*str != '\0')
	{
		str++;
		rozmiar++;
	}

	return rozmiar;


}

int main()
{
	const char* tekst = "";
	std::cout << myStrLen(tekst);
}