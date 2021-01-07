#include <iostream>
#include "book.h"
#include "bible.h"
#include <iostream>

int main(){
  std::string q = "which ordinal verse?: ";
  int ordinal_verse = 0;
  std::cout << q;
  std::cin >> ordinal_verse;
  std::cout << bible::canon[ordinal_verse].book_name << std::endl;  
  std::cout << bible::canon[ordinal_verse].verse << std::endl;
  std::cout << bible::canon[ordinal_verse].text << std::endl;  
  printf("EOF\n");
}
