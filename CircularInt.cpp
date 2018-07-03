#include "CircularInt.hpp"
/* Constructor */
CircularInt::CircularInt(int min , int max)
{
    if(max < min)
    {
        min_range = max;
        max_range = min;
        current_range = min_range;
    }
    else
    {
        min_range = min;
        max_range = max;
        current_range = min_range;
    }
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
const CircularInt CircularInt::operator+(const int num)
{
    CircularInt copy(*this);
    copy += num;
    return copy;
}
const CircularInt CircularInt::operator+(const CircularInt& c2)
{
    CircularInt temp(*this);
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
const CircularInt CircularInt::operator-(const int num)
{
    CircularInt copy(*this);
    copy -=num;
    return copy;
}
const CircularInt CircularInt::operator-(const CircularInt& c2)
{
    CircularInt temp(*this);
    temp -= c2;
    return temp;

}
CircularInt CircularInt::operator-()
{
    CircularInt copy(*this);
    copy *= (-1);
    return copy;
}
const CircularInt CircularInt::operator*(const int num)
{
    CircularInt copy(*this);
    copy *= num;
    return copy;
}
const CircularInt operator*(const int num , const CircularInt& c)
{
    CircularInt copy(c);
    copy *= num;
    return copy;
}
const CircularInt CircularInt::operator*(const CircularInt& c2)
{
    CircularInt copy(*this);
    copy *= c2.current_range;
    return copy;
}
const CircularInt CircularInt::operator/(const int num)
{
    CircularInt copy(*this);
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
const CircularInt CircularInt::operator%(const int num)
{
    CircularInt copy(*this);
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
bool CircularInt::operator==(const CircularInt c2)
{
    return this->current_range == c2.current_range;
}
bool CircularInt::operator==(const int num)
{
    return this->current_range == num;
}
bool operator==(const int num , const CircularInt c1)
{
    return c1.current_range == num;
}
bool CircularInt::operator!=(const CircularInt c2)
{
    return !(*this == c2);
}
bool CircularInt::operator!=(const int num)
{
    return !(this->current_range == num);
}
bool operator!=(const int num , const CircularInt c1)
{
    return !(c1.current_range == num);
}
bool CircularInt::operator>(const CircularInt c2)
{
    return this->current_range > c2.current_range;
}
bool CircularInt::operator>(const int num)
{
    return this->current_range > num;
}
bool operator>(const int num , const CircularInt c1)
{
    return num > c1.current_range;
}
bool CircularInt::operator<(const CircularInt c2)
{
    return this->current_range < c2.current_range;
}
bool CircularInt::operator<(const int num)
{
    return this->current_range < num;
}
bool operator<(const int num , const CircularInt c1)
{
    return num < c1.current_range;
}
bool CircularInt::operator>=(const CircularInt c2)
{
    return *this == c2 || *this > c2;
}
bool CircularInt::operator>=(const int num)
{
    return this->current_range >= num;
}
bool operator>=(const int num , const CircularInt c1)
{
    return num >= c1.current_range;
}
bool CircularInt::operator<=(const CircularInt c2)
{
    return *this == c2 || *this < c2;
}
bool CircularInt::operator<=(const int num)
{
    return this->current_range <= num;
}
bool operator<=(const int num , const CircularInt c1)
{
    return num <= c1.current_range;
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
        throw std::invalid_argument( "There is no such a number\n" );
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
    int num;
    input >> num;
    obj.current_range = num;
    obj += 0;
    return input;
}