// Q17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Two_D_Array.h"
#include <iostream>


int main()
{
  Two_D_Array<int, 3, 3> vec;
  vec.fill(4);
  std::cout << vec.at( 1, 1 ) << std::endl;
  return 0;
}

