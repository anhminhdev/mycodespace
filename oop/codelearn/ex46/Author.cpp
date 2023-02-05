#pragma once
#include <string>
using namespace std;

class Author
{
private:
  string name, email;

public:
  Author(string name, string email)
  {
    this->name = name;
    this->email = email;
  }
  void setName(string name)
  {
    this->name = name;
  }
  string getName()
  {
    return this->name;
  }
  void setEmail(string email)
  {
    this->email = email;
  }
  string getEmail()
  {
    return this->email;
  }
};
