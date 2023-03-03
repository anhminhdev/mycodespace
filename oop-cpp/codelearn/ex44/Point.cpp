class Point
{
private:
  int x, y;

public:
  Point() {}
  Point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
  void setX(int x)
  {
    this->x = x;
  }
  int getX()
  {
    return this->x;
  }
  void setY(int y)
  {
    this->y = y;
  }
  int getY()
  {
    return this->y;
  }
};