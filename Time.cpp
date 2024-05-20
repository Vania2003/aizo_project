#include "Time.h"

// Metoda startująca timer; zapisuje obecny czas jako punkt startowy.
void Time::startTimer() {
    start = chrono::high_resolution_clock::now();
}

// Metoda zatrzymująca timer; zapisuje obecny czas jako punkt końcowy.
void Time::stopTimer() {
    end = chrono::high_resolution_clock::now();
}

// Metoda obliczająca i zwracająca czas trwania pomiędzy startem a stopem.
// Wynik jest konwertowany z mikrosekundy.
double Time::getDuration() const {
    return chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
}
