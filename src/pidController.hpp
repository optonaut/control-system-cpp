/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#include "integral.hpp"
#include "derivative.hpp"

#ifndef CSTK_PID_CONTROLLER_HEADER
#define CSTK_PID_CONTROLLER_HEADER

namespace cstk {
    template <typename T, typename V>
    class PidController : Controller<T> {
    private: 
        V kp;
        Integral<T> I;
        V ki;
        Derivative<T> D;
        V kd;
    public:
        PidController(V kp, V ki, V kd, T initial) :
            kp(kp), I(initial), ki(ki), D(initial), kd(kd) { }
        
        T operator()(T v) {
            return kp * v + ki * I(v) + kd * D(v);
        }
    };

    template <typename T, typename V>
    PidController<T, V> CreatePidController(V kp, V ki, V kd, T initial) {
        return PidController<T, V>(kp, ki, kd, initial);
    }
}

#endif
