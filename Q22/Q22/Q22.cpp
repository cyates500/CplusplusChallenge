// Q22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


// all convertions
double deg_to_K ( double d )
{
  return (d + 273.0);
}

double K_to_deg ( double d )
{
  return (d - 273.0);
}

double f_to_deg ( double d )
{
  return ((d - 32.0) * 5.0 / 9.0);
}

double deg_to_f( double d )
{
  return (d * 9.0 / 5.0) + 32.0;
}

double f_to_K ( double d )
{
  return deg_to_K(f_to_deg(d));
}

double K_to_f ( double d )
{
  return deg_to_f(K_to_deg(d));
}

// literals
double operator"" _deg ( long double d )
{
  return deg_to_K(d);
}

double operator"" _f ( long double d )
{
  return f_to_K(d);
}

double operator"" _K ( long double d )
{
  return d;
}

int main()
{
  double temp1 = 100.0_deg;
  double temp2 = 90.0_f;
  std::cout << temp2 + temp1 << "K" << std::endl;
  if( 100.0_deg > 90.0_f )
  {
    std::cout << "it's true" << std::endl;
  }
  K_to_deg(temp1);

  return 0;
}

