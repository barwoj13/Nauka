#include <iostream>
#include <functional>
#include <vector>
#include <string>

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
	/*
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

	auto testowa = []()
		{
			std::cout << "Test" << std::endl;
		};
	testowa();

	auto testowa2 = [id = 0]() mutable
		{
			return id++;
		};

	std::cout << testowa2() << std::endl;
	std::cout << testowa2() << std::endl;
	*/
	
	// Vectory

	std::vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	for (int i = 0; i < numbers.size(); i++) 
	{
		std::cout << numbers[i] << std::endl;
	}

	std::vector<std::string> names = {"Bartek", "Marcel", "Sylwek", "Alan"};

	std::cout << "--- Petla indeksowana ---\n";
	for (size_t i = 0; i < names.size(); i++) {
		std::cout << names[i] << "\n";
	}

	std::cout << "--- Petla for-each ---\n";

	// for(auto name : names) // Operujemy na kopii elementu z vectora
	for (auto& name : names) // Operujemy na orginalnym elemencie
	{
		std::cout << name << "\n";
		name += "!";
	}
	// for(const auto& name : names) // Operujemy na sta³ej referencji i nie mamy mo¿liwoœci zmiany wartoœci, jest to najoptymalniejsze


	std::cout << numbers.front() << '\n'; // ---> Pierwszy element
	std::cout << numbers.back() << '\n'; // ---> Ostatni element

	// System oceniania z vectorami

	std::vector<int> grades = { 2,5,1,4,3,2,5,1,4 };

	// Poprawa 1 na 2 
	for (auto& grade : grades) 
	{
		if (grade == 1) 
		{
			grade = 2;
		}
	}

	double srednia = 0.0f;
	for (const auto& grade : grades) 
	{
		srednia += grade;
	}
	srednia /= grades.size();




	// Transformacja cen

	std::vector<double> netPrices = { 100.0, 50.0, 200.0, 15.0 };

	auto applyVAT = [](double cena)
		{
			return cena += cena * 0.23f;
		};

	std::vector<double> grossPrices;

	for (const auto& netPrice : netPrices) 
	{
		grossPrices.push_back(applyVAT(netPrice));
	}

	std::cout << "Ceny brutto" << std::endl;
	for (const auto& price : grossPrices) 
	{
		std::cout << price << "PLN\n";
	}


}