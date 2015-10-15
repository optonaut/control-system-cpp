/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#include "integral.hpp"
#include "derivate.hpp"

#ifndef CSTK_CONTROLLER_HEADER
#define CSTK_CONTROLLER_HEADER

namespace cstk {
    template <typename T, typename V>
    class PidController : Controller<T> {
    private: 
        V kp;
        Integral<T> I;
        V ki;
        Derivate<T> D;
        V kd;
    public:
        PidController(V kp, V ki, V kd, T initial) :
            kp(kp), i(initial), ki(ki), d(initial), kd(kd) { }
        
        T operator()(T v) {
            return kP * v + ki * I(v) + kd * D(v);
        }
    };

    template <typename T, typename V>
    CreatePidController(V kp, V ki, V kd, T initial) {
        return PidController<T, V>(kp, ki, kd, initial);
    }
}

#endif
