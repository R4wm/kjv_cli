#include <iostream>
#include <sqlite3.h>
#include "book.h"
#include "genesis.h"

static int callback(void *data, int argc, char **argv, char **azColName){
  int i;
  fprintf(stderr, "%s: ", (const char*)data);

  for(i = 0; i < argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i]: "NULL");
  }
  printf("\n");
  return 0;
}

template <typename T>
void get_verse(T x, int a_chapter, int a_verse){
  std::cout << x.book_name
            << " "
            << x.books[a_chapter].chapter
            << ":"
            << x.books[a_verse].verse
            << " "
            << x.books[a_verse].verse_text
            << std::endl;
}

int main(){
  sqlite3 *db;
  int rc;
  char *zErrMsg = 0;
  std::string db_path = "/tmp/kjv.db";
  const char* data = "Callback function called\n";
  rc = sqlite3_open(db_path.c_str(), &db);

  if(rc){
    fprintf(stderr, "Cant open database: %s\n", sqlite3_errmsg(db));
  }else{
    printf("Opened database ok: %s\n", db_path.c_str());
  }

  // just a POC
  Genesis gen;
  int chapter = 1;
  int verse = 1;

  get_verse<Genesis>(gen, chapter -1, verse -1);
  // SQL TESTING
  const char *sql_statement = "SELECT * from kjv";
  // rc = sqlite3_exec(db, sql_statement, callback, (void*)data, &zErrMsg);

  sqlite3_close(db);
  printf("EOF\n");
}
