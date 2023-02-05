#include "Point.cpp"
#include <cmath>

class Line
{
private:
  Point begin;
  Point end;

public:
  Line(Point begin, Point end)
  {
    this->begin = begin;
    this->end = end;
  }
  Line(int x1, int y1, int x2, int y2)
  {
    this->begin = Point(x1, y1);
    this->end = Point(x2, y2);
  }
  void setBegin(Point begin)
  {
    this->begin = begin;
  }
  Point getBegin()
  {
    return this->begin;
  }
  void setEnd(Point end)
  {
    this->end = end;
  }
  Point getEnd()
  {
    return this->end;
  }
  double getLength()
  {
    return sqrt(pow((this->begin.getX() - this->end.getX()), 2) + pow(this->begin.getY() - this->end.getY(), 2));
  }
};