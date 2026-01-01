//
// Created by Xia on 12/9/2025.
//

#ifndef POO2526_RANDOM_H
#define POO2526_RANDOM_H

#include <random>
class Random
{
public:
    Random() = delete;
    static int getRandom(int min, int max);
    static int getRandom(int max);

private:
    static std::mt19937 engine;
};


#endif //POO2526_RANDOM_H