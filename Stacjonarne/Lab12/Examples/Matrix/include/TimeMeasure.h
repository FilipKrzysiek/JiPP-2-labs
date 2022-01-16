//
// Created by filip on 16.01.2022.
//

#ifndef MATRIXTEST_TIMEMEASURE_H
#define MATRIXTEST_TIMEMEASURE_H

#include <chrono>

using namespace std;

class TimeMeasure {
private:
    chrono::time_point<chrono::high_resolution_clock> start;
    chrono::time_point<chrono::high_resolution_clock> end;

public:
    /**
     * Register start timer time
     */
    void timerStart();

    /**
     * Register end timer time
     */
    void timerStop();

    /**
     * Calculate timer time and return it in seconds
     * @return timer work time in seconds
     */
    long long int getTimerTimeInSeconds();

    /**
     * Calculate timer time and return it in milliseconds
     * @return timer work time in milliseconds
     */
    long long int getTimerTimeInMilliseconds();

    /**
     * Calculate timer time and return it in nanoseconds
     * @return timer work time in nanoseconds
     */
    long long int getTimerTimeInNanoseconds();
};


#endif //MATRIXTEST_TIMEMEASURE_H
