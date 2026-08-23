#include <iostream>
#include <string>

class Urzadzenie
{
private:
    std::string nazwa;

public:
    Urzadzenie(const std::string& nazwa)
        : nazwa(nazwa) {
    }

    virtual ~Urzadzenie() = default;

    std::string getNazwa() const { return nazwa; }

    void wlacz()
    {
        std::cout << "Wlaczono urzadzenie: " << nazwa << std::endl;
    }
};

// 1. Kluczowe jest s³owo 'virtual' TUTAJ:
class Drukarka : virtual public Urzadzenie
{
private:
    int liczbaKartek;

public:
    Drukarka(const std::string& nazwa, int liczba)
        : Urzadzenie(nazwa), liczbaKartek(liczba) {
    }
};

// 2. I TUTAJ:
class Skaner : virtual public Urzadzenie
{
private:
    int rozdzielcosc;

public:
    Skaner(const std::string& nazwa, int rozdzielcosc)
        : Urzadzenie(nazwa), rozdzielcosc(rozdzielcosc) {
    }
};

// 3. Dziedziczymy zwyczajnie publicznie z obu klas
class UrzadzenieWielofunkcyjne : public Drukarka, public Skaner
{
public:
    // Wypisanie konstruktora Urzadzenie(...) jest TUTAJ OBOWI¥ZKOWE, 
    // poniewa¿ Urzadzenie jest dziedziczone wirtualnie!
    UrzadzenieWielofunkcyjne(const std::string& nazwa, int kartki, int rozdzielcosc)
        : Urzadzenie(nazwa), Drukarka(nazwa, kartki), Skaner(nazwa, rozdzielcosc) {
    }
};

int main()
{
    UrzadzenieWielofunkcyjne uw("HP All-In-One", 250, 1200);

    // Dzia³a bez b³êdu jednoznacznoœci (ambiguity error)!
    // Istnieje tylko jeden podobiekt 'Urzadzenie'.
    uw.wlacz();
}