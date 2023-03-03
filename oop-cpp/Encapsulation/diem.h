#include <iostream>
#include <math.h>
using namespace std;

class diem
{
private:
    float x, y;

public:
    diem();         // Constructor
    diem(float, float); // Constructor with parameter
    diem(const diem &); // Constructor copy
    ~diem();        // Destructor

    void input();
    void output();

    // Encapsulation
    float getter_x();
    float getter_y();

    void setter_x(float);
    void setter_y(float);

    double calcDistance(diem);
};