#include "CircularInt.hpp"
/* Constructor */
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
/* Arithmetic operators */
CircularInt& CircularInt::operator=(const int num)
{
    this->current_range = num;
    (*this) += 0;
    return *this;
}
CircularInt& CircularInt::operator=(const CircularInt& c)
{
    this-> min_range = c.min_range;
    this->max_range = c.max_range;
    this->current_range = c.current_range;
    return *this;
}
const CircularInt operator+(const int num,const CircularInt& c )
{
    CircularInt copy(c);
    copy += num;
    return copy;
}
const CircularInt operator+(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy += num;
    return copy;
}
const CircularInt operator+(CircularInt const& c1 , CircularInt const& c2)
{
    CircularInt temp(c1);
    temp += c2;
    return temp;

}
const CircularInt operator-(const int num, CircularInt const& c )
{
    CircularInt copy(c);
    copy -= num;
    copy *= (-1);
    return copy;
}
const CircularInt operator-(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy -=num;
    return copy;
}
const CircularInt operator-(const CircularInt& c1 , const CircularInt& c2)
{
    CircularInt temp(c1);
    temp -= c2;
    return temp;

}
CircularInt CircularInt::operator-()
{
    CircularInt copy(*this);
    copy *= (-1);
    return copy;
}
const CircularInt operator*(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy *= num;
    return copy;
}
const CircularInt operator*(const int num , const CircularInt& c)
{
    CircularInt copy(c);
    copy *= num;
    return copy;
}
const CircularInt operator*(const CircularInt& c1 , const CircularInt& c2)
{
    CircularInt copy(c1);
    copy *= c2.current_range;
    return copy;
}
const CircularInt operator/(CircularInt const& c , const int num)
{
    CircularInt copy(c);
    copy /= num;
    return copy;
}
const CircularInt operator/(const int num , CircularInt const& c)
{
    CircularInt copy(c);
    copy.current_range = num/copy.current_range;
    copy += 0;
    return copy;
}
const CircularInt operator%(const CircularInt& c , const int num)
{
    CircularInt copy(c);
    copy %= num;
    return copy;
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
/* Comparison operators */
bool operator==(const CircularInt c1 , const CircularInt c2)
{
    return c1.current_range == c2.current_range;
}
bool operator==(const CircularInt c1 , const int num)
{
    return c1.current_range == num;
}
bool operator==(const int num , const CircularInt c1)
{
    return c1.current_range == num;
}
bool operator!=(const CircularInt c1 , const CircularInt c2)
{
    return !(c1 == c2);
}
bool operator!=(const CircularInt c1 , const int num)
{
    return !(c1.current_range == num);
}
bool operator!=(const int num , const CircularInt c1)
{
    return !(c1.current_range == num);
}
bool operator>(const CircularInt c1 , const CircularInt c2)
{
    return c1.current_range > c2.current_range
        && c1.max_range == c2.max_range &&
        c1.min_range == c2.min_range;
}
bool operator>(const CircularInt c1 , const int num)
{
    return c1.current_range > num;
}
bool operator>(const int num , const CircularInt c1)
{
    return c1.current_range > num;
}
bool operator<(const CircularInt c1 , const CircularInt c2)
{
    return c1.current_range < c2.current_range
        && c1.max_range == c2.max_range &&
        c1.min_range == c2.min_range;
}
bool operator<(const CircularInt c1 , const int num)
{
    return c1.current_range < num;
}
bool operator<(const int num , const CircularInt c1)
{
    return c1.current_range < num;
}
bool operator>=(const CircularInt c1 , const CircularInt c2)
{
    return c1 == c2 || c1 > c2;
}
bool operator>=(const CircularInt c1 , const int num)
{
    return c1.current_range >= num;
}
bool operator>=(const int num , const CircularInt c1)
{
    return c1.current_range >= num;
}
bool operator<=(const CircularInt c1 , const CircularInt c2)
{
    return c1 == c2 || c1 < c2;
}
bool operator<=(const CircularInt c1 , const int num)
{
    return c1.current_range <= num;
}
bool operator<=(const int num , const CircularInt c1)
{
    return c1.current_range <= num;
}
/* Compound assignment operators */
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
CircularInt& CircularInt::operator%=(const int other)
{
    current_range %= other;
    (*this)+=0;
    return *this;
}
/* IOstream */
ostream& operator<< (ostream& os ,CircularInt const& obj)
{
    os << obj.current_range;
    return os;
}
istream& operator>>(istream& input, CircularInt& obj)
{
    input >> obj.min_range >> obj.max_range;
    obj.current_range = obj.min_range;
    return input;
}