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
    while(current_range > max_range)
        current_range -= (max_range-min_range+1);
    while(current_range < min_range)
        current_range += (max_range-min_range+1);
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
    (*this)+=0;
    return *this;
}
CircularInt& CircularInt::operator/=(const int num)
{
    if(current_range % num == 0)
    {
        current_range /= num;
        (*this) += 0;
    }
    else 
    {
        stringstream ss;
        ss << "There is no number x in {" << min_range << "," << max_range << "} such that x*" << num << "=" << current_range;
        string s = ss.str();
        throw s;
    }
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
    copy *= (-1);
    return copy;
}
inline ostream& operator<< (ostream& os , const CircularInt& obj)
{
    os << obj.current_range;
    return os;
}
inline istream& operator>>(istream& input, CircularInt& obj)
{
    input >> obj.min_range >> obj.max_range;
    obj.current_range = obj.min_range;
    return input;
}
inline const CircularInt operator-(const int num,const CircularInt& c )
{
    CircularInt copy(c);
    copy -= num;
    copy *= (-1);
    return copy;
}
inline const CircularInt operator-(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy -=num;
    return copy;
}
inline const CircularInt operator-(const CircularInt& c1 , const CircularInt& c2)
{
    CircularInt temp(c1);
    temp -= c2;
    return temp;

}
inline const CircularInt operator+(const int num,const CircularInt& c )
{
    CircularInt copy(c);
    copy += num;
    return copy;
}
inline const CircularInt operator+(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy += num;
    return copy;
}
inline const CircularInt operator+(const CircularInt& c1 , const CircularInt& c2)
{
    CircularInt temp(c1);
    temp += c2;
    return temp;

}
inline const CircularInt operator/(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy /= num;
    return copy;
}
inline const CircularInt operator*(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy *= num;
    return copy;
}
inline const CircularInt operator*(const int num , const CircularInt& c)
{
    CircularInt copy(c);
    copy *= num;
    return copy;
}
inline const CircularInt operator%(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy %= num;
    return copy;
}
inline bool operator==(const CircularInt c1 , const CircularInt c2)
{
    return c1.current_range == c2.current_range
        && c1.max_range == c2.max_range &&
        c1.min_range == c2.min_range;
}
inline bool operator!=(const CircularInt c1 , const CircularInt c2)
{
    return !(c1 == c2);
}
inline bool operator>(const CircularInt c1 , const CircularInt c2)
{
    return c1.current_range > c2.current_range
        && c1.max_range == c2.max_range &&
        c1.min_range == c2.min_range;
}
inline bool operator<(const CircularInt c1 , const CircularInt c2)
{
    return c1.current_range < c2.current_range
        && c1.max_range == c2.max_range &&
        c1.min_range == c2.min_range;
}
inline bool operator>=(const CircularInt c1 , const CircularInt c2)
{
    return c1 == c2 || c1 > c2;
}
inline bool operator<=(const CircularInt c1 , const CircularInt c2)
{
    return c1 == c2 || c1 < c2;
}