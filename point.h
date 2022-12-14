#ifndef POINT_H
#define POINT_H

class Point
{
protected:
  int x;
  int y;

public:
  Point();
  Point(int x, int y);
  int getX();
  int getY();
  void setX(int x);
  void setY(int y);
};

#endif