#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class CircularInt{
private:
    /* Variable */
    int min_range; 
    int max_range;
    int current_range;
public:
    /* Constructor */
    CircularInt(int,int);
    CircularInt(const CircularInt&);
    /* Arithmetic operators */
    CircularInt& operator=(const int);
    CircularInt& operator=(const CircularInt&);
    friend const CircularInt operator+(const int,const CircularInt&);
    const CircularInt operator+(const int);
    const CircularInt operator+(const CircularInt&);
    friend const CircularInt operator-(const int,CircularInt const&);
    const CircularInt operator-(const int);
    const CircularInt operator-(const CircularInt&);
    CircularInt operator-();
    const CircularInt operator*(const int);
    friend const CircularInt operator*(const int num , const CircularInt& c);
    const CircularInt operator*(const CircularInt&);
    const CircularInt operator/(const int);
    friend const CircularInt operator/(const int,CircularInt const&); 
    const CircularInt operator%(const int);
    CircularInt& operator++();
    CircularInt operator++(const int);
    CircularInt& operator--();
    CircularInt operator--(const int);
    /* Comparison operators */
    bool operator==(const int);
    friend bool operator==(const int,const CircularInt);
    bool operator==(const CircularInt);
    bool operator!=(const CircularInt);
    bool operator!=(const int);
    friend bool operator!=(const int,const CircularInt); 
    bool operator>(const CircularInt); 
    bool operator>(const int);
    friend bool operator>(const int,const CircularInt); 
    bool operator<(const CircularInt);  
    bool operator<(const int);
    friend bool operator<(const int,const CircularInt); 
    bool operator>=(const CircularInt); 
    bool operator>=(const int);
    friend bool operator>=(const int,const CircularInt); 
    bool operator<=(const CircularInt); 
    bool operator<=(const int);
    friend bool operator<=(const int,const CircularInt); 
    /* Compound assignment operators */
    CircularInt& operator+=(const int);
    CircularInt& operator+=(const CircularInt&);
    CircularInt& operator-=(const int);
    CircularInt& operator-=(const CircularInt&);
    CircularInt& operator*=(const int);
    CircularInt& operator*=(const CircularInt&);  
    CircularInt& operator/=(const int);
    CircularInt& operator%=(const int);
    /* IOstream */
    friend ostream& operator<<(ostream&, CircularInt const&);
    friend istream& operator>>(istream&, CircularInt&);
};