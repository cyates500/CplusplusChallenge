// Q25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <regex>
#include <iostream>
#include <cassert>


//std::string capitalise_str ( const std::string& str )
// should this return or be a non const not returning
std::string capitalise_str ( const std::string& str )
{
  assert( !str.empty() );
  std::string capitalised_str = str;
  
  capitalised_str[0] = toupper( capitalised_str[0] );
  for( int l = 1 ; l < capitalised_str.size() ; ++l )
  {
    if ( isspace( capitalised_str[l - 1] ) )
    {
      capitalised_str[l] = toupper( capitalised_str[l] );
    }
  }
  return capitalised_str;
}

bool test_function( const std::string& input, const std::string expected )
{
  return expected == capitalise_str(input);
}



int main()
{
  std::cout << capitalise_str ( "the c++ challenge" ) << std::endl;
  if ( test_function( "the\nc++ challenge", "The\nC++ Challenge") )
  {
    std::cout << "test passed" << std::endl;
  }
  else
  {
    std::cout << "test failed" << std::endl;
  }
  return 0;
}

