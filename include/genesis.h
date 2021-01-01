#ifndef GENESIS_H
#define GENESIS_H

#include <string>

// THIS FILE WILL HAVE TO BE GENERATED FROM SQL QUERIES
class Genesis{

  struct A{
    const int chapter;
    const int verse;
    const std::string verse_text;
  };

public:
  const std::string book_name = "GENESIS";
  int something = 1;
  A books[3] = {1,1,"In the beginning"};
};

#endif // GENSIS_H
