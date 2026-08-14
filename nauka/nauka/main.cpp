#include <iostream>
#include <functional>

// Lambda

auto message = []() // Lambda jako zwyk³a funkcja
	{
		std::cout << "Hello World!" << std::endl;
	};

auto dodaj = [](int a, int b) // Lambda jako funkcja z argumentami
	{
		return a + b;
	};

void mojaFunkcja(std::function<void()> func) // Przekazanie lambdy/funkcji do innej funkcji
{
	func();
	func();
}



int main() 
{

	// Lambda

	int x = 67;

	auto przekazanie1 = [x]() // Capture clause - pozwoli nam na przekazanie do lambdy jakiejœ zmiennej
		{
			std::cout << x << std::endl;
		};

	auto przekazanie2 = [&x]() 
		{
			std::cout << x << std::endl;
		};


	x = 34; // Lambda przekazanie1 i tak pokaze numer 67, bo przechowuje ona kopie wartosci tej zmiennej, natomiast przekazanie2 przechowuje ostatni¹ wartoœæ spod adresu wiêc poka¿e 34 teraz

	message();
	
	std::cout << dodaj(1, 2) << std::endl;

	mojaFunkcja(message);

	for (int i = 0; i < 3; i++) 
	{
		auto wylicz = [i]() // Lambda z u¿yciem pêtli
			{
				std::cout << "Liczba: " << i << std::endl;
			};
		wylicz();	
	}

	przekazanie1();
	przekazanie2();
}