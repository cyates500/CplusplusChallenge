// Q60 GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Grid.h"

int main()
{
  Grid grid( 50, 20 );
  grid.print_cells();
  return 0;
}

