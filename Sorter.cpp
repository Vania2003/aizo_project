#include "Sorter.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Time.h"

// Wyświetla aktualne dane w konsoli.
void Sorter::display() const {
    if (data.empty()) {
        cout << "Data vector is empty." << endl;
    } else {
        for (const auto& value : data) {
            cout << fixed << setprecision(3) << value << " ";
        }
        cout << endl;
    }
}

// Sortuje dane metodą przez wstawianie.
void Sorter::insertionSort() {
    for (int i = 1; i < data.size(); i++) {
        double key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Sortuje dane metodą bąbelkową.
void Sorter::bubbleSort() {
    bool swapped;
    for (int i = 0; i < data.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Metody do realizacji sortowania przez scalanie.
void Sorter::merge(vector<double>& left, vector<double>& right, vector<double>& bars) {
    int nL = left.size(), nR = right.size();
    int i = 0, j = 0, k = 0;
    while (j < nL && k < nR) {
        if (left[j] < right[k]) bars[i++] = left[j++];
        else bars[i++] = right[k++];
    }
    while (j < nL) bars[i++] = left[j++];
    while (k < nR) bars[i++] = right[k++];
}

void Sorter::mergeSortRecursive(vector<double>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;
        vector<double> left(arr.begin(), arr.begin() + mid);
        vector<double> right(arr.begin() + mid, arr.end());

        mergeSortRecursive(left);
        mergeSortRecursive(right);
        merge(left, right, arr);
    }
}

void Sorter::mergeSort() {
    mergeSortRecursive(data);
}

// Metoda sprawdzająca, czy dane są posortowane.
bool Sorter::isSorted() const {
    for (int i = 0; i < data.size() - 1; i++) {
        if (data[i] > data[i + 1]) return false;
    }
    return true;
}

// Wczytywanie danych z pliku.
void Sorter::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "File not found." << endl;
        return;
    }
    data.clear();
    double value;
    while (file >> value) {
        data.push_back(value);
    }
    file.close();
}

// Testowanie i mierzenie czasu sortowania.
void Sorter::testSort(const string& sortType) {
    Time timer;
    timer.startTimer(); // Rozpoczęcie pomiaru czasu

    if (sortType == "insertion") {
        insertionSort();
    } else if (sortType == "bubble") {
        bubbleSort();
    } else if (sortType == "merge") {
        mergeSort();
    }

    timer.stopTimer(); // Zakończenie pomiaru czasu
    cout << "Time taken for " << sortType << " sort: " << timer.getDuration() << " ms" << endl;
}
