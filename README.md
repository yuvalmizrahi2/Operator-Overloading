Operators-Overload  
===  

Assignment 4 and 5 in a C++ course  

Authors:
--
Yuval Mizrahi  
Inon Peer  
Aviv Rovshitz

**Intoduction**
==

About the assignment:
-- 
Create a class called CircularInt that represent an integer in a circular math, 
for example an hour in a clock.  
This object is initiate as the minimal number in the range.  
The object is changed by operators, for example:  
CircularInt ci (1,12); ci current number will be initiate as the minimal number - 1.  
 ci += 13 ---> ci will use a function called normalize after adding 1+13 = 14,  
so that the current number will be in the range :  
14 - 12 = 2 ---> current number - the amount of numbers in the range = until it'll give a nubmer in range.

**File list:**
--  

```  
.: 
.gitignore 
CircularInt.cpp  
CircularInt.hpp  
README  .md  
main.cpp
```  
Further look into the classes:  
--  
1. **main.cpp** - This class has some examples to run and check the code with it.  
2. **CircularInt.hpp** - This class defines this new object called CircularInt. Its fields are :   
*min_range* - The minimal number for the range.  
*max_range* - Th maximal number for the range.  
*current_range* - The current number in the range.  
3. **CircularInt.cpp** - This class defines all the functions needed for CircularInt, and all the operators overload.  

Compile Command:  
--  
g++ -std=c++11 *.cpp  
need to add a main to the completion level  

[©Kineret Ruth Nahary](https://github.com/Kineruth)
