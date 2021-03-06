// Q61 Unary Function Paralell transform.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>

int unary_func ( int val )
{
  return val + 1;
}

//template < typename T >
std::vector<int> transform ( const std::vector<int>::iterator& first, const std::vector<int>::iterator& last, std::function<int ( int )> transformation )
{
  std::vector<int> transformed_vec;
  std::transform ( first, last, std::back_inserter ( transformed_vec ), transformation );
  return transformed_vec;
}


int main ()
{
  std::vector<int> vec = { 1, 2, 3, 4, 5 };
  std::vector<int> changed_vec = transform ( vec.begin (), vec.end (), unary_func );
  std::cout << "{ ";
  for (auto i : changed_vec)
  {
    std::cout << i << ", ";
  }
  std::cout << " }" << std::endl;
  return 0;
}
