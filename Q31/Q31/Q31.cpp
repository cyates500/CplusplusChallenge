// Q31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <regex>
#include <iostream>
#include <map>

std::string change_date ( const std::string& date )
{
  if ( std::regex_match( date, std::regex( R"([0123]\d\.[012]\d\.[012]\d\d\d|[0123]\d\-[012]\d\-[012]\d\d\d)") ) )
  {
    std::string changed_date = date;
    //year
    for( int i = 0; i <= 3; ++i )
    {
      changed_date[i] = date[i+6];
    }
    changed_date[4] = '-';
    //month
    changed_date[5] = date[3];
    changed_date[6] = date[4];
    changed_date[7] = '-';
    //day
    changed_date[8] = date[0];
    changed_date[9] = date[1];
    return changed_date;
  }
  std::cout << "not correct format" << std::endl;
  return date;
}

std::string change_datev ( std::string& date )
{
  std::regex rx = std::regex( R"((\d{1,2})(\.|\-|\)(\d{1,2})(\.|\-|\)(\d{4})" );
  return std::regex_replace( date.data, rx, std::regex( R"($5-$3-$1)" ) );
}
bool test_function( const std::string& input, const std::string& expected )
{
  return expected == change_date( input );
}

int main()
{
  std::map<std::string, std::string> tests = {{"05.09.1995", "1995-09-05"},
                                              {"05-09-1995", "1995-09-05"}};
  //tests.emplace(std::make_pair( "05.09.1995", "1995-09-05" ));
  //tests.emplace(std::make_pair( "05-09-1995", "1995-09-05" ));
  for( auto test: tests )
  {
    std::cout << test_function( test.first, test.second ) << std::endl;
    std::cout << change_date ( test.first ) << std::endl;
  }
  return 0;
}

