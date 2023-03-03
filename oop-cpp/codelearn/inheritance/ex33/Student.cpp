#pragma once
#include "Person.cpp"

class Student : public Person
{
private:
  double gpa;

public:
  Student(string name, int age, string address, double gpa) : Person(name, age, address)
  {
    this->gpa = gpa;
  }
  void setGpa(double gpa)
  {
    this->gpa = gpa;
  }
  double getGpa()
  {
    return this->gpa;
  }
  void display()
  {
    Person::display();
    cout << "Gpa: " << getGpa() << endl;
  }
};