// Q61 Unary Function Paralell transform.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <catch.hpp>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <iterator>
//#include <iostream>
//#include <utility>
//#include <experimental

int unary_func ( int val )
{
  return ++val;
}

TEST_CASE( "unary_func correctly computes", "[unary_func]" )
{
  REQUIRE( unary_func ( 1 ) == 2 );
}

//template < typename Iterator, typename F >
//void transform ( Iterator first, Iterator last, F& f )
//{
//  std::transform ( first, last, first, f );
//  //std::transform ( std::execution::parallel, first, last, first, f );
//}


//int main()
//{
//  std::vector<int> vec = { 1, 2, 3, 4, 5 };
//  transform( vec.begin(), vec.end(), unary_func );
//  std::cout << "{ ";
//  for( auto i : vec )
//  {
//    std::cout << i << ", ";
//  }
//  std::cout << " }" << std::endl;
//  return 0;
//}



