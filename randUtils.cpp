#include "randUtils.h"





double randUtils::getRand(double mean, double stdev)
    {
    // creates a uniform dist of numbers between two numbers
    // creates a normal distribution with a mean and variance
    std::normal_distribution<> distribution{mean, stdev};
    // mt picks out a number from our distrubtion, giving us our number (I think)
    return distribution(mt);
    }