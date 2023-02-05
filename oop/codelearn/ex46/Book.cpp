#include "Author.cpp"
#include <vector>

class Book
{
private:
  string name;
  vector<Author> authors;
  double price;

public:
  Book(string name, vector<Author> authors, double price)
  {
    this->name = name;
    this->authors = authors;
    this->price = price;
  }
  string getName(string name)
  {
    return name;
  }
  void setName()
  {
    this->name = name;
  }
  void setPrice(double price)
  {
    this->price = price;
  }
  double getPrice()
  {
    return price;
  }
  string getAuthorNames()
  {
    string res = "";
    for (int i = 0; i < authors.size() - 1; i++)
    {
      res += authors[i].getName() + ", ";
    }
    res += authors[authors.size() - 1].getName();
    return res;
  }
};