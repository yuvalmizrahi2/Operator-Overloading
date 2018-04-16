#include "CircularInt.hpp"

CircularInt::CircularInt(int min , int max)
{
    min_range = min;
    max_range = max;
    current_range = min;
};
CircularInt::CircularInt(const CircularInt& other)
{
    min_range = other.min_range;
    max_range = other.max_range;
    current_range = other.current_range;
};
CircularInt& CircularInt::operator+=(const int other)
{
    current_range += other;
    if(current_range > max_range)
        current_range %= max_range;
    while(current_range <= min_range - 1)
        current_range += max_range;
    return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& other)
{
    (*this) += other.current_range;
    return *this;
}
CircularInt& CircularInt::operator-=(const int other)
{
    (*this) += (-1)*other;
    return *this;
}
CircularInt& CircularInt::operator-=(const CircularInt& other)
{
    (*this) -= other.current_range;
    return *this;
}
CircularInt& CircularInt::operator*=(const int other)
{
    current_range *= other;
    (*this) += 0;
    return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& other)
{
    (*this) *= other.current_range;
    return *this;
}
CircularInt& CircularInt::operator%=(const int other)
{
    current_range %= other;
    return *this;
}
CircularInt& CircularInt::operator/=(const int other)
{
    *this = *this/other;
    return *this;
}
CircularInt& CircularInt::operator++()
{
    (*this) += 1;
    return *this;
}
CircularInt CircularInt::operator++(const int other)
{
    CircularInt copy(*this);
    ++(*this);
    return copy;
}
CircularInt& CircularInt::operator--()
{
    (*this) -= 1;
    return *this;
}
CircularInt CircularInt::operator--(const int other)
{
    CircularInt copy(*this);
    --(*this);
    return copy;
}
CircularInt CircularInt::operator-()
{
    CircularInt copy(*this);
    if(copy.current_range == copy.max_range)
        copy.current_range = copy.min_range;
    else if(copy.current_range == copy.min_range)
        copy.current_range = copy.max_range;
    else
        copy.current_range = copy.max_range - copy.current_range;
    return copy;
}