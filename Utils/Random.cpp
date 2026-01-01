//
// Created by Xia on 12/9/2025.
//
#include "Random.h"

std::mt19937 Random::engine = std::mt19937(std::random_device{}());

int Random::getRandom(int min, int max) {
    std::uniform_int_distribution<int> distribution = std::uniform_int_distribution<int>(min, max);
    return distribution(engine);
}

int Random::getRandom(int max) {
    return getRandom(0, max);
}