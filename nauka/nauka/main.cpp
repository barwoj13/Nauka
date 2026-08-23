#include <iostream>
#include <string>

class Pracownik
{
protected:
    std::string imie;

public:
    Pracownik(const std::string& imie) : imie(imie) {}

    // Wirtualny destruktor – gwarantuje wywo³anie w³aœciwego destruktora przy delete
    virtual ~Pracownik() = default;

    // Czysto wirtualna metoda (= 0) – klasa staje siê abstrakcyjna
    virtual double obliczPensje() = 0;
};

class PracownikEstatowy : public Pracownik
{
private:
    double pensjaPodstawowa;

public:
    PracownikEstatowy(const std::string& imie, double pensjaPodstawowa)
        : Pracownik(imie), pensjaPodstawowa(pensjaPodstawowa) {
    }

    double obliczPensje() override
    {
        return pensjaPodstawowa;
    }
};

class PracownikGodzinowy : public Pracownik
{
private:
    double stawkaGodzinowa;
    int liczbaGodzin;

public:
    PracownikGodzinowy(const std::string& imie, double stawkaGodzinowa, int liczbaGodzin)
        : Pracownik(imie), stawkaGodzinowa(stawkaGodzinowa), liczbaGodzin(liczbaGodzin) {
    }

    double obliczPensje() override
    {
        return stawkaGodzinowa * liczbaGodzin;
    }
};

int main()
{
    // Poprawne polimorficzne zarzadzanie pamiecia
    Pracownik* tablica[] = {
        new PracownikEstatowy("Jan", 4500.0),
        new PracownikGodzinowy("Chrzan", 30.0, 160)
    };

    for (int i = 0; i < 2; i++)
    {
        std::cout << tablica[i]->obliczPensje() << std::endl;
    }

    // Sprz¹tanie pamiêci – tutaj kluczowy jest wirtualny destruktor!
    for (int i = 0; i < 2; i++)
    {
        delete tablica[i];
    }
}