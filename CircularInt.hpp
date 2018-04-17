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