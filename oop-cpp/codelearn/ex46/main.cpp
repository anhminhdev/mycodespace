#include <iostream>
#include "Author.cpp"
#include "Book.cpp"
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