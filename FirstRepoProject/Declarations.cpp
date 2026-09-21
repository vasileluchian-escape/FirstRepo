
//@#pragma once // does the same as the 3 # underneth however it is not used as it only works on Mircosoft ( not cross platform )
// 
//#include <iostream> - will skip projects folder and look for it inside system and library
//#include "mathHelpers.h" - will first look for it in the projects folder than after in the system library folder 



// INCLUDE GUARDS
#ifndef MATHHELPERS_H // #ifndef - if this lable in not defined, we will define it underneth, if it is defined, it will skip whatever alread is here
#define MATHHELPERS_H
int Square(int value);
int Doble(int value);
#endif  // #endif ends the definion of whatever lable we needed to define. Now we do #include "file_name" in whatver other file we need to include this and use it

