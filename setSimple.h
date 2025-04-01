#ifndef SETSIMPLE_H
#define SETSIMPLE_H

#include <iostream>
#include <vector>

class setSimple {
private:
    std::vector<bool> tablica;
    int rozmiar;

public:
    setSimple() : rozmiar(0) {}

    setSimple(const std::vector<int>& elementy) { //konstruktor przyjmujacy elemrnty do zbioru
        rozmiar = 0; //ustawiamy rozmiar na 0
        for (int x : elementy) { //przechodzimy kazdy element z podanych
            if (x >= 0) rozmiar = std::max(rozmiar, x + 1); //na podstawie elementy ustalamy rozmiar +1
        }
        tablica.resize(rozmiar, false); //ustawiamy tablice o danym rozmiarze na 0
        for (int x : elementy) { //przechodzimy znow przez elementy
            if (x >= 0) tablica[x] = true; //ustawiamy elementy na 1
        }
    }

    void wstawianie(int x) {
        if (x < 0) return; //tylko dla dodatnich liczb
        if (x >= rozmiar) { //jezeli liczba jest wieksza niz obecny rozmiar
            tablica.resize(x + 1, false); //rozszerzamy tablice do tego elementu i ustawiamy go na false
            rozmiar = x + 1; //zwiekszamy rozmiar
        }
        tablica[x] = true; //ustawiamy element na true
    }

    void usuwanie(int x) {
        if (x >= 0 && x < rozmiar && tablica[x]){
            tablica[x] = false;
        }
    }

    bool zawieranie(int x) const {
        return (x >= 0 && x < rozmiar) && tablica[x];
    }

    setSimple operator+(const setSimple& other) const {
        setSimple wynik;
        wynik.rozmiar = std::max(rozmiar, other.rozmiar); //zmieniamy rozmiar na wiekszy
        wynik.tablica.resize(wynik.rozmiar, false); //ustalamy tablice na false
        for (int i = 0; i < wynik.rozmiar; i++) { //petla po kazdym elemencie
            if ((i < rozmiar && tablica[i]) || (i < other.rozmiar && other.tablica[i])) { //jezeli ktorys element jest ok to wstaw
                wynik.tablica[i] = true;
            }
        }
        return wynik;
    }

    setSimple operator-(const setSimple& other) const {
        setSimple wynik(*this); //tworzymy wynik jako zbior_A
        for (int i = 0; i < std::min(rozmiar, other.rozmiar); i++) { //iterujemy do mniejszego rozmiaru
            if (other.tablica[i]) wynik.tablica[i] = false; //jezeli jest w zbior_B to usun go z A
        }
        return wynik;
    }

    setSimple operator&(const setSimple& other) const {
        setSimple wynik;
        wynik.rozmiar = std::min(rozmiar, other.rozmiar);
        wynik.tablica.resize(wynik.rozmiar, false);
        for (int i = 0; i < wynik.rozmiar; i++) {
            if (tablica[i] && other.tablica[i]) wynik.tablica[i] = true;
        }
        return wynik;
    }
};

#endif