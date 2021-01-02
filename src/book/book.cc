#include "book.h"

const int stuff = 1;

Book::Book(){
  printf("NOthing book!\n");
}

Book::Book(std::string a_book_name){
  book_name = a_book_name;
  printf("Created %s\n", a_book_name.c_str());
}


void Book::say_hi(){
  printf("HI\n");
}

