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
  A books[3][4] = {{{1,1,"In the beginning"}, {1,2, "This is chapter1 verse 2"}}, {2,1, "this is text of chapter 2:1"}, {2,2, "this is text of chapter 2:2"}}; // saying has 3 books and max of 4 verses per book.. (not sure how to arbitrary array matrixs)
};

#endif // GENSIS_H
