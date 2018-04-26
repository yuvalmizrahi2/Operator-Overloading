#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class CircularInt{
private:
    
public:
    /* Variable */
    int min_range; 
    int max_range;
    int current_range;
    /* Constructor */
    CircularInt(int min , int max);
    CircularInt(const CircularInt& other);
    /* Arithmetic operators */
    CircularInt& operator=(const int num);
    CircularInt& operator=(const CircularInt& c);
    friend const CircularInt operator+(const int num , const CircularInt& c);
    friend const CircularInt operator+(const CircularInt& c , const int num);
    friend const CircularInt operator+(CircularInt const& c1 , CircularInt const& c2);
    friend const CircularInt operator-(const int num , CircularInt const& c);
    friend const CircularInt operator-(const CircularInt& c , const int num);
    friend const CircularInt operator-(const CircularInt& c1 , const CircularInt& c2);
    CircularInt operator-();
    friend const CircularInt operator*(const CircularInt& c , const int num);
    friend const CircularInt operator*(const int num , const CircularInt& c);
    friend const CircularInt operator*(const CircularInt& c1 , const CircularInt& c2);
    friend const CircularInt operator/(CircularInt const& c , const int num);
    friend const CircularInt operator/(const int num , CircularInt const& c); //check this
    friend const CircularInt operator%(const CircularInt& c , const int num);
    CircularInt& operator++();
    CircularInt operator++(const int other);
    CircularInt& operator--();
    CircularInt operator--(const int other);
    /* Comparison operators */
    friend bool operator==(const CircularInt c1 , const int num);//check this
    friend bool operator==(const int num ,const CircularInt c1);//check this
    friend bool operator==(const CircularInt c1 , const CircularInt c2);
    friend bool operator!=(const CircularInt c1 , const CircularInt c2);
    friend bool operator!=(const CircularInt c1 , const int num);//check this
    friend bool operator!=(const int num ,const CircularInt c1);//check this 
    friend bool operator>(const CircularInt c1 , const CircularInt c2); 
    friend bool operator>(const CircularInt c1 , const int num);//check this
    friend bool operator>(const int num ,const CircularInt c1);//check this 
    friend bool operator<(const CircularInt c1 , const CircularInt c2);  
    friend bool operator>=(const CircularInt c1 , const CircularInt c2); 
    friend bool operator<=(const CircularInt c1 , const CircularInt c2); 
    /* Compound assignment operators */
    CircularInt& operator+=(const int other);
    CircularInt& operator+=(const CircularInt& other);
    CircularInt& operator-=(const int other);
    CircularInt& operator-=(const CircularInt& other);
    CircularInt& operator*=(const int other);
    CircularInt& operator*=(const CircularInt& other);  
    CircularInt& operator/=(const int other);
    CircularInt& operator%=(const int other);
    /* IOstream */
    friend ostream& operator<<(ostream& os, CircularInt const& obj);
    friend istream& operator>>(istream& input, CircularInt& obj);
};