#include <iostream>
using namespace std;

class Animal
{
public:
  void sound()
  {
    cout << "some sound";
  }
};
  
class Dog : public Animal
{
public:
  void sound()
  {
    cout << "woof woof";
  }
};

int main()
{
  Animal animal;
  Dog *d = (Dog *)&animal; // up-casting
  d->sound();
  return 0;
}