#pragma once

#include <vector>
#include <array>
#include <algorithm>


template <typename T, int SIZE_X, int SIZE_Y>
class Two_D_Array
{
public:
  using ArrayT = std::array<T, ( SIZE_X * SIZE_Y )>;
  
  void fill( const T& t )
  {
    std::fill( m_elems.begin(), m_elems.end(), t );
  }
  
  void swap( Two_D_Array& arr )
  {
    m_elems.swap( arr.m_elems ); 
  }
  // raises exception if the combination of x and y are invalid
  T& at( const int& x, const int& y)
  {
    if( x > SIZE_X )
    {
      throw ( "" );
    }
    if( y > SIZE_Y )
    {
      throw ( "" );
    }
      return m_elems.at( (x * SIZE_X) + y );
    // TO DO need to raise exception.
  }

  constexpr size_t size()
  {
    return m_elems.size();
  }

  
  // capacity()
  // Look at std array and see if it provides move semantics.
  // TRY unique pointer with move and copy
private:
  ArrayT m_elems;
};