#include "randUtils.h"
#include <iostream>
#include <chrono> // for delay (std::chrono_literals)
#include <thread> // for delays (std::this_thread)




double randUtils::getRand(double mean, double stdev)
    {
    // creates a uniform dist of numbers between two numbers
    // creates a normal distribution with a mean and variance
    std::normal_distribution<> distribution{mean, stdev};
    // mt picks out a number from our distrubtion, giving us our number (I think)
    return distribution(mt);
    }


void randUtils::delayMillis(int millis)
{
    for (int i{0}; i < 5; i++)
    {
    std::cout << "." << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(millis));
    }

}


void randUtils::delayMillisNoDots(int millis)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}

