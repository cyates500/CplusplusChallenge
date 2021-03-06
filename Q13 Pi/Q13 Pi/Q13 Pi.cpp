// Q13 Pi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <utility>

int RAD = 500;
int DI  = RAD * 2;
int LOOP_INV = 100000;
int EST_RATIO = 4;
float EST_RATIO_FLOAT = 4;

int rand_di()
{
  return rand() % (DI +1);
}

std::pair<int, int> coord_rand_di()
{
  return std::make_pair( rand_di(), rand_di() );
}

bool is_in_circle( std::pair< int, int> coord )
{
  return ( ( ( coord.first - RAD ) * ( coord.first - RAD ) ) +
    ( ( coord.second - RAD ) * ( coord.second - RAD ) ) )
    < ( RAD * RAD );
}

int estimate_pi()
{
  int i = 0;
  int count = 0;
  while( i < LOOP_INV )
  {
    ++i;
    if(is_in_circle( coord_rand_di() ))
    {
      ++count;
    }
  }
  return EST_RATIO * count;
}

float estimate_pi_float ()
{
  int i = 0;
  float count = 0;
  while (i < LOOP_INV)
  {
    ++i;
    if (is_in_circle ( coord_rand_di () ))
    {
      ++count;
    }
  }
  return EST_RATIO_FLOAT * count / LOOP_INV;
}

int main()
{
  //std::cout << rand_di() << std::endl;
  //std::cout << coord_rand_di().first << " , " << coord_rand_di().second << std::endl;
  std::cout << estimate_pi() << std::endl;
  std::cout << estimate_pi_float() << std::endl;
    return 0;
}

