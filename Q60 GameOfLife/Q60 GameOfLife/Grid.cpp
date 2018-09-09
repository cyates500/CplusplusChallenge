#include "stdafx.h"
#include "Grid.h"
#include <iostream>

Grid::Grid(int rows, int cols)
{
  m_row_size = cols;
  m_col_size = rows;
  m_cells.resize( rows * cols );
  for( int i = 0; i < rows ; ++i )
  {
    for( int j = 0; j < cols ; ++j )
    {
      Cell cell ( 1, i, j );
      m_cells[i * rows + j] = cell;
    }
  }
}

  //std::vector<bool> Grid::get_surrounding_cell_states ( int row, int col )
  //{
  //std::vector<bool> surrounding_states;
  //for (int i = -1; i <= 1; ++i)
  //{
  //  for (int j = -1; j <= 1; ++j)
  //  {
  //    if (!( i == 0 && j == 0 ))
  //    {
  //      surrounding_states.push_back ( m_cells[( row + i ) * m_row_size + col + j].get_state () );
  //    }
  //  }
  //}
  //return surrounding_states;
  //}


//void Grid::update ()
//{
//  for (Cell cell : m_cells)
//  {
//    cell.update( get_surrounding_cell_states(cell.get_row(), cell.get_col()) );
//  }
//}

void Grid::print_cells()
{
  int prev_cell_row = 0;
  for( Cell cell : m_cells )
  {
    if (cell.get_row () > prev_cell_row)
    {
      std::cout << std::endl;
    }
    if( cell.get_state() )
    {
      std::cout << 1;
    }
    else
    {
      std::cout << " ";
    }
    prev_cell_row = cell.get_row();
  }
}