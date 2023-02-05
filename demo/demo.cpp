#include <string>
#include <vector>
#include <iostream>
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
    this->name;
  }
  string getName()
  {
    return this->name;
  }
  void setEmail(string email)
  {
    this->email;
  }
  string getEmail()
  {
    return this->email;
  }
};

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
    string res;
    for (int i = 0; i < authors.size() - 1; i++)
    {
      res += authors[i].getName() + ", ";
    }
    res += authors[authors.size() - 1].getName();
    return res;
  }
};

int main()
{
  vector<Author> authors;
  authors.push_back(Author("Viet", "VietCV@codelearn.io"));
  authors.push_back(Author("Tuan", "TuanLQ7@codelearn.io"));
  authors.push_back(Author("KienNT", "KienNT@codelearn.io"));

  Book book1("C++ for Beginners", authors, 210000);
  cout << book1.getAuthorNames();
  return 0;
}