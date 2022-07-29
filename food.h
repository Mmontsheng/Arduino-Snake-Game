#include "point.h"

#ifndef FOOD_H
#define FOOD_H

class Food: public Point {
  public:
  using Point::Point;
  void generate();
};

#endif
