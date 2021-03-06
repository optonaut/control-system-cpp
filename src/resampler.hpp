/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#ifndef CSTK_RESAMPLER_HEADER
#define CSTK_RESAMPLER_HEADER

namespace cstk {
    template typename<T>
    class Controller {
    private: 
    public:
        virtual T operator()(T value);
    }
}

#endif
