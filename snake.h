#include "point.h"
#ifndef SNAKE_H
#define SNAKE_H

class Snake : public Point
{
private:
  int dx = 0;
  int dy = 0;
  int length =1;

public:
  using Point::Point;
  void update();
  void eat();
  void setLength(int length);
  void setDirection(int dx, int dy);
};

#endif