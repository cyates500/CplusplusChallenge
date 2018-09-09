#pragma once

#include <vector>
#include "Cell.h"

class Grid
{
public:
  Grid(int rows, int cols);
  //void update();
  //std::vector<bool> get_surrounding_cell_states( int row, int col );
  void print_cells();
  //template <typename Func>
  //delctype(Func) for_each_surrounding_cell(int row, int col, Func fn )
  //{
  //  // iterate over cells surrounding row, col, invoking fn on them

  //}
private:
  std::vector<Cell> m_cells;
  int m_row_size;
  int m_col_size;
};