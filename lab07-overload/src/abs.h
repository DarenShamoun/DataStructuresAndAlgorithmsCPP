#ifndef CISC187_MESA_ABS_H
#define CISC187_MESA_ABS_H

namespace mesa
{
    auto abs();

    constexpr
        unsigned abs(const unsigned value)
    {
        return value < 0 ? -value : value;
    }

    constexpr
        unsigned char abs(const unsigned char value)
    {
        return value < 0 ? -value : value;
    }

    constexpr
        int abs(const int value)
    {
        return value < 0 ? -value : value;
    }

    constexpr
        long abs(const long value)
    {
        return value < 0 ? -value : value;
    }

    constexpr
        double abs(const double value)
    {
        return value < 0 ? -value : value;
    }

    constexpr
        long long abs(const long long value)
    {
        return value < 0 ? -value : value;
    }

    constexpr
        long double abs(const long double value)
    {
        return value < 0 ? -value : value;
    }

    constexpr
        unsigned long abs(const unsigned long value)
    {
        return value < 0 ? -value : value;
    }
}

#endif // !CISC187_MESA_ABS_H