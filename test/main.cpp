#include <iostream>
#include <cassert>
#include "CircularInt.hpp"
using namespace std;
CircularInt hour {3, 10};
CircularInt testing(3,10);
void test1(){
	assert(hour.min_range == 3 && hour.max_range == 10 && hour.current_range == hour.min_range);
}
void test2(){
	hour += 7;
	assert(hour.current_range == 10);
	testing += 5; // 8
	hour += testing;
	assert(hour.current_range == 10);
}
void test3(){
	hour -= 7;
	assert(hour.current_range == 3);
	testing -= 12; // 4
	hour -= testing;
	assert(hour.current_range == 7);
}
void test4(){
	hour *= 4;
	assert(hour.current_range == 4);
	testing *= 4; // 8
	hour *= testing; //8
	assert(hour.current_range == 8);
}
void test5(){
	try{
		hour /= 3;
	}
	catch (const string& message){
		cout << message << endl;
	}
	try{
		hour /= 2;
	}
	catch (const string& message){
		cout << message << endl;
	}
	assert(hour.current_range == 4);
	hour += 10;
	hour %= 2;
	assert(hour.current_range == 8);

}
void test6(){
	(hour+=2)++;
	assert(hour.current_range == 3);
	++hour;
	assert(hour.current_range == 4);
	(testing -=2)--;
	assert(testing.current_range == 5);
}
void test7(){
	testing = -testing;
	assert(testing.current_range == 3);
}
void test8(){
	hour = testing;
	assert(hour.current_range == 3);
	hour = 13;
	assert(hour.current_range == 5);
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
	test8();
	cout << "the testing has finishd";
}