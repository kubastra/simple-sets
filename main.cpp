#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include "setSimple.h"
#include <algorithm>
#include <random>
#include <unordered_set>

std::ofstream file("time.dat");

void mierzenie_wstawiania(setSimple &zbior, int element, int iteration) {//przyjmujemy sobie iteracje zeby ja tez wypisac do pliku dat
    auto start = std::chrono::high_resolution_clock::now(); //rozpoczynamy zegar
    zbior.wstawianie(element); //wstawiamy element
    auto stop = std::chrono::high_resolution_clock::now(); //konczymy zegar
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); //obliczamy ilosc nanosekund
    file << iteration << " " << duration.count() << " "; //wypisujemy do pliku
}

void mierzenie_usuwania(setSimple &zbior, int element) {
    auto start = std::chrono::high_resolution_clock::now();
    zbior.usuwanie(element);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    file << duration.count() << " ";
}

void mierzenie_sumy(setSimple &zbior_A, setSimple &zbior_B) {
    setSimple suma;
    auto start = std::chrono::high_resolution_clock::now();
    suma = zbior_A + zbior_B;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    file << duration.count() << " ";
}

void mierzenie_wspolnej(setSimple &zbior_A, setSimple &zbior_B) {
    setSimple wspolna;
    auto start = std::chrono::high_resolution_clock::now();
    wspolna = zbior_A & zbior_B;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    file << duration.count() << " ";
}

void mierzenie_roznicy(setSimple &zbior_A, setSimple &zbior_B) {
    setSimple roznica;
    auto start = std::chrono::high_resolution_clock::now();
    roznica = zbior_A - zbior_B;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    file << duration.count() << "\n";
}

int main() {
    if (!file) { //jezeli plik sie nie chce otworzyc to daj znac
        std::cerr << "Nie udało się otworzyć pliku do zapisu!" << std::endl;
        return 1;
    }
    std::random_device rd; //uruchamiamy ziarno do generatora
    std::mt19937 gen(rd()); // inicjalizujemy pseudolosowy generator

    for (int iteration = 1; iteration <= 3000; ++iteration) {

        std::unordered_set<int> dane_A; //niepowtarzalne zbiory
        std::unordered_set<int> dane_B;
        std::uniform_int_distribution<int> dist(0, iteration); //zaseig losowosci do iteration

        while (dane_A.size() < iteration) dane_A.insert(dist(gen)); //wstawiamy do dane
        while (dane_B.size() < iteration) dane_B.insert(dist(gen));

        setSimple zbior_A(std::vector<int>(dane_A.begin(), dane_A.end())); //tworzymy zbiory jako vectory jak w setsimple
        setSimple zbior_B(std::vector<int>(dane_B.begin(), dane_B.end()));

        // Mierzenie czasu operacji
        mierzenie_wstawiania(zbior_A, iteration, iteration);
        mierzenie_usuwania(zbior_A, iteration);
        mierzenie_sumy(zbior_A, zbior_B);
        mierzenie_wspolnej(zbior_A, zbior_B);
        mierzenie_roznicy(zbior_A, zbior_B);
    }

    file.close();
    std::cout << "Dane zapisane do time.dat" << std::endl;

    return 0;
}
