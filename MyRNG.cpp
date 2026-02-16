#include "MyRNG.h"
#include <ctime>
#include <chrono>
#include <cmath>
#include <vector>

/*
 * This class acts as a pseudorandom number generator, made by me :)
 *
 * By Brendan Ross
 * 2026-2-16
 */

double MyRNG::myRandom() {
    clock_t start = clock();
    time_t currentTime = time(nullptr);
    tm*  currentLocalTime = localtime(&currentTime);
        for(int i = 0; i < currentLocalTime->tm_sec; i++) {
            std::vector<int> list;
            for(int j = 0; j < 100; j++) {
                list.push_back(j);
            }
            list.shuffle(list.begin(), list.end());
            sort(list.begin(), list.end());
        }
        
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::system_clock::duration timeSinceEpoch = now.time_since_epoch();
    int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceEpoch).count();
    clock_t end = clock();
    clock_t runningTime = end - start;

    if (runningTime == 0) {
        runningTime = 2;
    }

    double randomNumber = M_PI * milliseconds / runningTime;
    return floor(randomNumber);
}