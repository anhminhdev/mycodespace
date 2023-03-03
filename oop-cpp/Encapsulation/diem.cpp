#include "diem.h"

// Default Constructor
diem::diem()
{
    this->x = this->y = 0;
}

// Constructor with parameter
diem::diem(float x, float y)
{
    this->x = x;
    this->y = y;
}

// Constructor copy
diem::diem(const diem &a)
{
    this->x = a.x;
    this->y = a.y;
}

// Destructor
diem::~diem()
{
    // If private of class have variable pointer, delete it.
}

// Input class infomation
void diem::input()
{
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}

void diem::output()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

// Getter
float diem::getter_x()
{
    return x;
}
float diem::getter_y()
{
    return y;
}

// Setter
void diem::setter_x(float x)
{
    this->x = x;
}
void diem::setter_y(float y)
{
    this->y = y;
}

double diem::calcDistance(diem d)
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}