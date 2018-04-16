#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class CircularInt{
private:
    
public:
    int min_range; 
    int max_range;
    int current_range;
    CircularInt(int min , int max);
    CircularInt(const CircularInt& other);
    friend ostream& operator<<(ostream& os, const CircularInt& obj);
    friend istream& operator>>(istream& input, CircularInt& obj);
    CircularInt& operator+=(const int other);
    CircularInt& operator+=(const CircularInt& other);
    CircularInt& operator-=(const int other);
    CircularInt& operator-=(const CircularInt& other);
    CircularInt& operator*=(const int other);
    CircularInt& operator*=(const CircularInt& other);
    CircularInt& operator%=(const int other);
    CircularInt& operator/=(const int other);
    CircularInt& operator++();
    CircularInt operator++(const int other);
    CircularInt& operator--();
    CircularInt operator--(const int other);
    CircularInt operator-();
    friend const CircularInt operator-(const int num , const CircularInt& c);
    friend const CircularInt operator-(const CircularInt& c , const int num);
    friend const CircularInt operator-(const CircularInt& c1 , const CircularInt& c2);
    friend const CircularInt operator+(const int num , const CircularInt& c);
    friend const CircularInt operator+(const CircularInt& c , const int num);
    friend const CircularInt operator+(const CircularInt& c1 , const CircularInt& c2);
    friend const CircularInt operator/(const CircularInt& c , const int num);
    friend const CircularInt operator*(const CircularInt& c , const int num);
    friend const CircularInt operator*(const int num , const CircularInt& c);
    friend const CircularInt operator%(const CircularInt& c , const int num);
    friend bool operator==(const CircularInt c1 , const CircularInt c2);
    friend bool operator!=(const CircularInt c1 , const CircularInt c2); 
    friend bool operator>(const CircularInt c1 , const CircularInt c2); 
    friend bool operator<(const CircularInt c1 , const CircularInt c2);  
    friend bool operator>=(const CircularInt c1 , const CircularInt c2); 
    friend bool operator<=(const CircularInt c1 , const CircularInt c2); 
};
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
    if(copy.current_range % num == 0)
    {
        copy.current_range /= num;
    }
    else 
    {
        stringstream ss;
        ss << "There is no number x in {" << copy.min_range << "," << copy.max_range << "} such that x*" << num << "=" << copy.current_range;
        string s = ss.str();
        throw s;
    }
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