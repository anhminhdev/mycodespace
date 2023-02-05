#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
protected:
  string name;
  int age;
  string address;

public:
  Person(string name, int age, string address)
  {
    this->name = name;
    this->age = age;
    this->address = address;
  }
  // getter
  string getName()
  {
    return this->name;
  }
  int getAge()
  {
    return this->age;
  }
  string getAddress()
  {
    return this->address;
  }

  // setter
  void setName(string name)
  {
    this->name = name;
  }
  void setAge(int age)
  {
    this->age = age;
  }
  void setAddress(string address)
  {
    this->address = address;
  }

  void display()
  {
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Address: " << getAddress() << endl;
  }
};