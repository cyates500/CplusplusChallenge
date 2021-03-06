// Q4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool is_prime( unsigned int num )
{
  for( unsigned int candidate_factor = 2; candidate_factor <= num/2; ++candidate_factor )
  {
    if( num % candidate_factor == 0 )
    {
      return false;
    }
  }
  return true;
}

unsigned int solution( unsigned int number )
{
  for( unsigned int candidate_num = number - 1; candidate_num > 1; --candidate_num)
  {
    if( is_prime( candidate_num ))
    {
      std::cout << candidate_num << std::endl;
      return candidate_num;
    }
  }
  return 0;
}

bool test_solution( unsigned int input, unsigned int expected )
{
  return expected == solution( input );
}

bool test_prime( unsigned int input, unsigned int expected )
{
  return expected == is_prime( input );
}


int main()
{
  
  //if( is_prime( 7 ) && is_prime(19) && is_prime(29) )
  //{
  //  std::cout << "test success" << std::endl;
  //}
  if(
  !test_solution ( 6, 5 ) ||
  !test_solution ( 10, 7 ) ||
  !test_solution ( 20, 19 ))
  {
    std::cout << "test failed" << std::endl;
  }

  return 0;
}

