#include <iostream>
#include <string>


class Pojazd
{
private:
	std::string marka;

protected:
	int rokProdukcji;

public:
	Pojazd(const std::string& marka, int rokProdukcji) 
		:marka(marka), rokProdukcji(rokProdukcji) {}

	std::string getMarka() const { return marka; }

	void wyswietlInfo() const 
	{
		std::cout << marka << " : " << rokProdukcji << std::endl;
	}
};

class Samochod : public Pojazd
{
private:
	int liczbaDrzwi;
public:
	Samochod(const std::string& marka, int rokProdukcji, int liczbaDrzwi)
		:Pojazd(marka, rokProdukcji), liczbaDrzwi(liczbaDrzwi) {}

	void wyswietlSzczegol() const 
	{
		std::cout << getMarka() << " : " << rokProdukcji << " : " << liczbaDrzwi << std::endl;
	}

};


int main()
{

}