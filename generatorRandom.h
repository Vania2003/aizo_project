#ifndef AIZO_GENERATORRANDOM_H
#define AIZO_GENERATORRANDOM_H

#include <vector>
#include <random>
#include <algorithm>
#include <type_traits>

template<typename T>
class generatorRandom {
public:
    static std::vector<T> generate(int size, int mode = 0);
};

template<typename T>
std::vector<T> generatorRandom<T>::generate(int size, int mode) {
    T min = -1000000;  // Minimalna wartość
    T max = 1000000;   // Maksymalna wartość
    std::vector<T> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> distrib(min, max);
        std::generate(data.begin(), data.end(), [&]() { return distrib(gen); });
    } else if constexpr (std::is_floating_point<T>::value) {
        std::uniform_real_distribution<T> distrib(min, max);
        std::generate(data.begin(), data.end(), [&]() { return distrib(gen); });
    }

    switch (mode) {
        case 1: // Losowe dane.
            break;
        case 2: // Sortowanie rosnąco.
            std::sort(data.begin(), data.end());
            break;
        case 3: // Sortowanie malejąco.
            std::sort(data.begin(), data.end(), std::greater<T>());
            break;
        case 4: // Częściowo sortowanie - 33% danych.
            std::sort(data.begin(), data.begin() + (size * 33 / 100));
            break;
        case 5: // Częściowo sortowanie - 66% danych.
            std::sort(data.begin(), data.begin() + (size * 66 / 100));
            break;
    }

    return data;
}

#endif //AIZO_GENERATORRANDOM_H
