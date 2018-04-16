#include <iostream>
#include <cassert>
#include "CircularInt.hpp"
using namespace std;
CircularInt hour {1, 12};
CircularInt testing(1,12);
void test1(){
	assert(hour.min_range == 1 && hour.max_range == 12 && hour.current_range == hour.min_range);
}
void test2(){
	hour += 12;
	assert(hour.current_range == 1);
	testing += 5;
	hour += testing;
	assert(hour.current_range == 7);
}
void test3(){
	hour -= 7;
	assert(hour.current_range == 12);
	testing -= 12;
	hour -= testing;
	assert(hour.current_range == 6);
}
void test4(){
	hour *= 4;
	assert(hour.current_range == 12);
	testing *= 4;
	hour *= testing;
	assert(hour.current_range == 12);
}
void test5(){
	hour /= 3;
	assert(hour.current_range == 4);
	hour += 10;
	hour %= 8;
	assert(hour.current_range == 2);


}
void test6(){
	(hour+=2)++;
	assert(hour.current_range == 5);
	++hour;
	assert(hour.current_range == 6);
	(testing -=2)--;
	assert(testing.current_range == 9);
}
void test7(){
	testing = -testing;
	assert(testing.current_range == 4);
}
int main() 
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	cout << "the testing has finishd";
}