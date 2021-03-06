// Q51_Phone_Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

#include <range\v3\all.hpp>

namespace PhoneNumber
{
  bool is_valid_number ( const std::string& number )
  {
    if ( number.size() == 11 && number[0] == '0' )
    {
      return true;
    }
    return false;
  }

  

  void transform_number ( std::string& number )
  {
    if ( is_valid_number ( number ) )
    {
      number.erase( std::remove( number.begin(), ++number.begin(), '0' ) );
      number = "+44" + number;
    }
    else
    {
      std::cout << "not a valid number" << std::endl;
    }
  }

}

int main()
{
  std::string n = "07772752524";
  //std::cout << n.size() << std::endl;
  PhoneNumber::transform_number ( n );
  std::cout << n << std::endl;
    return 0;
}

