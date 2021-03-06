// Q54 Pairwise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


//see problem Q54
// What it does 
// undefined behaviour
// pre and post conditions - does it input and output
// describe parameters
// complexity ie performance
//std::vector<std::pair<int, int>> pairwise_int( std::vector<int>::const_iterator begin, 
//                                               std::vector<int>::const_iterator end )
//{
//  std::vector<std::pair<int, int>> result;
//
//  if( begin == end )
//  {
//    return result;
//  }
//
//  for ( auto i = begin ; i < std::prev( end ) ; ++(++i) )
//  {
//    result.push_back ( std::make_pair( *i, *( std::next(i) ) ) );
//  }
//  return result;
//}

template< typename T >
std::vector<std::pair<T, T>> pairwise ( typename std::vector<T>::const_iterator begin,
                                        typename std::vector<T>::const_iterator end )
{
  std::vector<std::pair<T, T>> result;

  if (begin == end)
  {
    return result;
  }

  for (auto i = begin; i < std::prev ( end ); ++( ++i ))
  {
    result.push_back ( std::make_pair ( *i, *( std::next ( i ) ) ) );
  }
  return result;
}

//Container being a template and the template object.
//template< typename T, template<class T,class Alloc> class Container>
//Container<std::pair<T, T>, Alloc> pairwise ( typename Container::const_iterator begin,
//                                      typename Container::const_iterator end )
//{
//  Container<std::pair<T, T>> result;
//
//  if (begin == end)
//  {
//    return result;
//  }
//
//  for (auto i = begin; i < std::prev ( end ); ++( ++i ))
//  {
//    result.push_back ( std::make_pair ( *i, *( std::next ( i ) ) ) );
//  }
//  return result;
//}

int main()
{
  std::vector<int> vec = { 1,2,3 };
  auto res = pairwise<int>( vec.begin(), vec.end() );
  std::for_each( res.begin(), res.end(),
                 [](const auto& pair){ std::cout << "{ "<< pair.first << ", " << pair.second << " }" << std::endl; } );
  return 0;
}

