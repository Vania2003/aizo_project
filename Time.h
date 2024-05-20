#ifndef TIME_H
#define TIME_H

#include <chrono>
using namespace std;

// Klasa Time wykorzystuje mechanizmy biblioteki chrono do mierzenia czasu.
// Pozwala na precyzyjne pomiary czasu wykonania określonych fragmentów kodu.
class Time {
private:
    // Zmienne do przechowywania punktów czasowych - początku i końca pomiaru.
    chrono::time_point<chrono::high_resolution_clock> start, end;

public:
    void startTimer();
    void stopTimer();
    double getDuration() const;
};

#endif // TIME_H
