#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// Klasa Sorter służy do przechowywania i sortowania danych.
// Wspiera różne metody sortowania.
class Sorter {
private:
    vector<double> data;  // Przechowuje dane do sortowania.

public:
    // Wczytuje dane z wektora.
    template<typename T>
    void load(const vector<T>& input_data) {
        data.clear();
        data.reserve(input_data.size());
        for (const T& value : input_data) {
            data.push_back(static_cast<double>(value));
        }
    }

    // Wyświetla posortowane dane.
    void displaySorted() const {
        display();
    }

    void insertionSort();
    void bubbleSort();
    void mergeSort();
    bool isSorted() const; // Sprawdza, czy dane są posortowane.

    // Metody do realizacji sortowania przez scalanie.
    void merge(vector<double>& left, vector<double>& right, vector<double>& bars);
    void mergeSortRecursive(vector<double>& arr);

    void loadFromFile(const string &filename);
    void display() const;
    void testSort(const string &sortType);
};

#endif // SORTER_H
