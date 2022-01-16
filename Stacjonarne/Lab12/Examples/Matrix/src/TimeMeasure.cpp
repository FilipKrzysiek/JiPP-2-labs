//
// Created by filip on 16.01.2022.
//

#include "TimeMeasure.h"

void TimeMeasure::timerStart() {
    start = chrono::high_resolution_clock::now();
}

void TimeMeasure::timerStop() {
    end = chrono::high_resolution_clock::now();
}

long long int TimeMeasure::getTimerTimeInSeconds() {
    return chrono::duration_cast<chrono::seconds>(end - start).count();
}

long long int TimeMeasure::getTimerTimeInMilliseconds() {
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

long long int TimeMeasure::getTimerTimeInNanoseconds() {
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}
