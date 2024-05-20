#include <conio.h>
#include <iostream>
#include <string>
#include <chrono>
#include "Time.h"
#include "Sorter.h"
#include "generatorRandom.h"

using namespace std;
using namespace std::chrono;

// Funkcja wyświetlająca menu główne programu
void displayMenu(const string& info) {
    cout << endl;
    cout << info << endl;
    cout << "1. Load from file" << endl;
    cout << "2. Generate randomly" << endl;
    cout << "3. Display array" << endl;
    cout << "4. Sort by insertion" << endl;
    cout << "5. Sort by merging" << endl;
    cout << "6. Bubble sort" << endl;
    cout << "7. Test (measurements)" << endl;
    cout << "0. Return to menu" << endl;
    cout << "Choose an option: ";
}

Sorter sorter; // Instancja klasy Sorter do zarządzania danymi i sortowaniem

// Główna funkcja zarządzająca interakcją z użytkownikiem
void menu_sorting() {
    char opt;           // Opcja wybrana przez użytkownika
    string fileName;    // Nazwa pliku do wczytania
    int size;           // Rozmiar tablicy do generacji
    int dataType;       // Typ danych do generacji

    do {
        displayMenu("--- SORTING MENU ---");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignoruje pozostałości w buforze
        opt = _getche();
        cout << endl;

        switch (opt) {
            case '1':
                cout << "Enter file name: ";
                cin >> fileName;
                sorter.loadFromFile(fileName);
                sorter.display();
                break;
            case '2':
                cout << "Enter array size: ";
                cin >> size;
                cout << "Insert data type (1 for int, 2 for float, 3 for double): ";
                cin >> dataType;
                cout << "Choose data kind (1-Random, 2-Ascending, 3-Descending, 4-Partially sorted 33%, 5-Partially sorted 66%): ";
                int mode;
                cin >> mode;
                switch (dataType) {
                    case 1:
                        sorter.load(generatorRandom<int>::generate(size, mode));
                        break;
                    case 2:
                        sorter.load(generatorRandom<float>::generate(size, mode));
                        break;
                    case 3:
                        sorter.load(generatorRandom<double>::generate(size, mode));
                        break;
                }
                sorter.display();
                break;
            case '3':
                sorter.display();
                break;
            case '4': // Sortowanie przez wstawianie
                cout << "Sorting array by insertion sort.\n";
                sorter.insertionSort();
                sorter.displaySorted();
                cout << (sorter.isSorted() ? "Array is sorted." : "Array is NOT sorted.") << endl;
                break;
            case '5': // Sortowanie przez scalanie
                cout << "Sorting array by merge sort.\n";
                sorter.mergeSort();
                sorter.displaySorted();
                cout << (sorter.isSorted() ? "Array is sorted." : "Array is NOT sorted.") << endl;
                break;
            case '6': // Sortowanie bąbelkowe
                cout << "Sorting array by bubble sort.\n";
                sorter.bubbleSort();
                sorter.displaySorted();
                cout << (sorter.isSorted() ? "Array is sorted." : "Array is NOT sorted.") << endl;
                break;
            case '7': {
                cout << "Choose sort type (insertion, bubble, merge): ";
                string sortType;
                cin >> sortType;
                Time timer;
                timer.startTimer();

                if (sortType == "insertion") {
                    sorter.insertionSort();
                } else if (sortType == "bubble") {
                    sorter.bubbleSort();
                } else if (sortType == "merge") {
                    sorter.mergeSort();
                }

                timer.stopTimer();
                cout << "Time taken for " << sortType << " sort: " << timer.getDuration() << " ms" << endl;
                break;
            }

            case '0':
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (opt != '0');
}

// Główna funkcja programu, która uruchamia menu
int main() {
    char option;
    do {
        cout << "==== MAIN MENU ====" << endl;
        cout << "1. Sorting" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        option = _getche();
        cout << endl;

        if (option == '1') {
            menu_sorting();
        }
    } while (option != '0');

    return 0;
}
