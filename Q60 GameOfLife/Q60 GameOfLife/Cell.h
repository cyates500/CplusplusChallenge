#pragma once

#include <vector>

class Cell
{
public:
  Cell( bool state, int row, int col );
  Cell();
  void update( std::vector<bool> surrounding_states );
  void death();
  void birth();
  bool get_state();
  int get_row();
  int get_col();
private:
  bool m_state;
  int m_row_index;
  int m_col_index;
};