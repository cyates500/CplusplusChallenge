#include "stdafx.h"
#include "Cell.h"

Cell::Cell( bool state, int row, int col)
{
  m_row_index = row;
  m_col_index = col;
  m_state = state;
}

Cell::Cell()
{
  m_row_index = 0;
  m_col_index = 0;
  m_state = 0;
}

int Cell::get_col()
{
  return m_col_index;
}

int Cell::get_row()
{
  return m_row_index;
}

void Cell::death()
{
  if( m_state == 1 )
  {
    m_state = 0;
  }
}

void Cell::birth()
{
  if( m_state == 0 )
  {
    m_state = 1;
  }
}

void Cell::update(std::vector<bool> surrounding_states)
{
  int sum = 0;
  for( bool state : surrounding_states )
  {
    if( state )
    {
      ++sum;
    }
  }

  if( sum < 2 )
  {
    death();
  }
  
  if( sum > 3 )
  {
    death();
  }

  if( sum == 3 )
  {
    birth();
  }
}

bool Cell::get_state()
{
  return m_state;
}