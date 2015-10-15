/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#include <cassert>
#include <random>
#include "../src/derivative.hpp"

int main() {
    cstk::Derivative<double> D(0);
    std::mt19937 ran;
    std::normal_distribution<> dist(10, 5);

    double l = 0;

    for(int i = 0; i < 10; i++) {
        double v = dist(ran);
        assert(D(v) == l - v);
        l = v;
    }

    return 0;
}
