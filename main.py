import matplotlib.pyplot as plt
import numpy as np

# Wczytanie danych
iteracje = []
czasy_wstawianie = []
czasy_usuwanie = []
czasy_suma = []
czasy_wspolna = []
czasy_roznica = []

with open('time.dat', 'r') as file:
    for line in file:
        data = list(map(int, line.split()))
        iteracje.append(data[0])
        czasy_wstawianie.append(data[1])
        czasy_usuwanie.append(data[2])
        czasy_suma.append(data[3])
        czasy_wspolna.append(data[4])
        czasy_roznica.append(data[5])

# Tworzenie wykresów
fig, axs = plt.subplots(3, 2, figsize=(12, 12))
fig.suptitle('Złożoności operacji na zbiorach')

axs[0, 0].plot(iteracje, czasy_wstawianie, marker='o', linestyle='-', color='b')
axs[0, 0].set_title('Czas Wstawiania')
axs[0, 0].set_xlabel('Rozmiar zbioru')
axs[0, 0].set_ylabel('Czas (ns)')
axs[0, 0].grid(True)

axs[0, 1].plot(iteracje, czasy_usuwanie, marker='o', linestyle='-', color='r')
axs[0, 1].set_title('Czas Usuwania')
axs[0, 1].set_xlabel('Rozmiar zbioru')
axs[0, 1].set_ylabel('Czas (ns)')
axs[0, 1].grid(True)

axs[1, 0].plot(iteracje, czasy_suma, marker='o', linestyle='-', color='g')
axs[1, 0].set_title('Czas Sumy Zbiorów')
axs[1, 0].set_xlabel('Rozmiar zbioru')
axs[1, 0].set_ylabel('Czas (ns)')
axs[1, 0].grid(True)

axs[1, 1].plot(iteracje, czasy_wspolna, marker='o', linestyle='-', color='purple')
axs[1, 1].set_title('Czas Części Wspólnej')
axs[1, 1].set_xlabel('Rozmiar zbioru')
axs[1, 1].set_ylabel('Czas (ns)')
axs[1, 1].grid(True)

axs[2, 0].plot(iteracje, czasy_roznica, marker='o', linestyle='-', color='orange')
axs[2, 0].set_title('Czas Różnicy Zbiorów')
axs[2, 0].set_xlabel('Rozmiar zbioru')
axs[2, 0].set_ylabel('Czas (ns)')
axs[2, 0].grid(True)

# Ukrycie pustego wykresu
axs[2, 1].axis('off')

plt.tight_layout()
plt.show()