/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#include "controller.hpp"

#ifndef CSTK_DERIVATIVE_HEADER
#define CSTK_DERIVATIVE_HEADER

namespace cstk {
    template <typename T>
    class Derivative : Controller<T> {
    private: 
        T last;
    public:
        Derivative(T initial) : last(initial) { }
        T operator()(T value) {
            T d = last - value;
            last = value;
            return d;
        }
    };

    typedef Derivative<double> DerivativeD;
}

#endif
