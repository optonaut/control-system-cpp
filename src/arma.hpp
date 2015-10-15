/**********************************************************************
 *
 * Part of project control-system-toolkit
 *
 * Copyright (c) Emanuel Joebstl <emanuel.joebstl@gmail.com>
 *
 *********************************************************************/

#include <array>

#ifndef CSTK_CONTROLLER_HEADER
#define CSTK_CONTROLLER_HEADER

namespace cstk {
    template <typename T, typename V, size_t n, size_t m>
    class ARMAFilter : Controller<T> {
    private:
        std::array<n, V> a;
        std::array<m, V> b;
        std::array<n, T> y;
        std::array<n, T> e;
        T initial;
    public:
        ARMAFilter(std::array<n, V> a, std::array<m, V> b, T initial) : a(a), b(b), initial(initial) {
            
            static_assert(n > 0, "Convolutive ARMA coefficients must be provided");

            std::fill(y, y + n, initial);
            std::fill(e, e + n, initial);
        }
        T operator()(T value) {
            T at = initial;
            T bt = initial;

            //Convultive Filter
            for(size_t i = 0; i < arma.m; i++) {
                bt += arma.b[i] / arma.a[0] * arma.e[i];
            }

            //Recursive Filter
            for(i = 1; i < arma.n; i++) {
                at += -arma.a[i] / arma.a[0] * arma.y[i - 1];
            }

            T yt = at + bt;

            //Advance in time
            for(i = arma.n - 1; i > 0; i--) {
                arma.y[i] = arma.y[i - 1];
            }
            arma.y[0] = yt;

            for(i = arma.m - 1; i > 0; i--) {
                arma.e[i] = arma.e[i - 1];
            }
            arma.e[0] = et;

            return yt;
        }
    };

    template <typename T, typename V, size_t n, size_t m>
    CreateARMAController(std::array<n, V> a, std::array<m, V> b, T initial) {
        return ARMAController<T, V, n, m>(a, b, initial);
    }
}

#endif

