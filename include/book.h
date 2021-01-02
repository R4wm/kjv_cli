#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
  enum Testament{OLD=1,NEW};
  
public:
  struct A{
    const int chapter;
    const int verse;
    const std::string verse_text;
  };
  
  Book();
  Book(std::string); // book name
  std::string book_name;
  int chapter;
  int verse_num;
  std::string verse_text;

  void say_hi();  

};
#endif // BOOK_H
