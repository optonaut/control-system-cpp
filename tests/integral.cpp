/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#include <cassert>
#include "../src/integral.hpp"

int main() {
    cstk::Integral<double> I(0);
    double sum = 0;

    for(int i = 0; i < 10; i++) {
        sum += i;
        assert(I(i) == sum);
    }

    return 0;
}
