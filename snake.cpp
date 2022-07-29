#include "snake.h"
#include "constants.h"

void Snake::update()
{
  this->x += dx;
  this->y += dy;

  if (this->x <= 0)
  {
    this->x = MAX_COLS;
  }
  if (this->x > MAX_COLS)
  {
    this->x = 0;
  }
  if (this->y <= 0)
  {
    this->y = MAX_ROWS;
  }
  if (this->y > MAX_ROWS)
  {
    this->y = 0;
  }
}

void Snake::setLength(int length)
{
  this->length = length;
}

void Snake::setDirection(int dx, int dy)
{
  this->dx = dx;
  this->dy = dy;
}