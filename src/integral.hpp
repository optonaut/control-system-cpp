/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#include "controller.hpp"

#ifndef CSTK_INTEGRAL_HEADER
#define CSTK_INTEGRAL_HEADER

namespace cstk {
    template <typename T>
    class Integral : Controller<T> {
    private: 
        T sum;
    public:
        Integral(T initial) : sum(initial) { }
        virtual T operator()(T value) {
            sum = sum + value;
            return sum;
        }
    };
    
    typedef Integral<double> IntegralD;
}

#endif
