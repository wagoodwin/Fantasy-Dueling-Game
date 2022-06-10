#ifndef RANDUTILS_H
#define RANDUTILS_H

#include <random>


namespace randUtils
{

    // std::mt19937 mt: creates a Mersenne Twister PRNG
    // std::random_device{}(): creates seed for PRNG
    // use "static" so we don't reseed every time mt is called
    static std::mt19937 mt{std::random_device{}()};

    double getRand(double mean, double stdev);


}






#endif