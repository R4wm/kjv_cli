#include <iostream>
#include <sqlite3.h>
#include "book.h"
#include "genesis.h"

static int callback(void *data, int argc, char **argv, char **azColName){
  int l_counter = 0;
  int i;
  fprintf(stderr, "%s: ", (const char*)data);

  for(i = 0; i < argc; i++){
    l_counter++;
    printf("counter: %d\n", l_counter);
    printf("On i: %d\n", i);
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i]: "NULL");
  }
  printf("\n");
  return 0;
}

template <typename T>
void get_verse(T x, int a_chapter, int a_verse){
  std::cout << x.book_name
            << " "
            << x.books[a_chapter][a_verse].verse_text
            << std::endl;

  // testing class defined map
  x.say_hi();
  std::cout << x.book_borders.at("JOHN").max_verse << std::endl;
}

int main(){
  ////////////////
  // just a POC //
  ////////////////
  Genesis gen;
  int chapter = 1;
  int verse = 1;
  const int offset = 1;
  get_verse<Genesis>(gen, chapter -offset, verse -offset);
  get_verse<Genesis>(gen, 2 -offset, 1-offset);
  
  /////////////////
  // SQL TESTING //
  /////////////////
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

  const char *sql_statement = "SELECT * from kjv";
  // START STEP TEST
  sqlite3_stmt *res;
  // sqlite3_prepare_v2(database_handle, SQL_Statement_utf8, max_number_of_bytes, statement_handle, pointer_to_unused_porttion_of_zSql)
  rc = sqlite3_prepare_v2(db, "SELECT * from kjv", -1, &res, 0);
  if(rc != SQLITE_OK){
    fprintf(stderr, "failed to fetch dta: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // std::string l_chapter_hold = "";
  // while(sqlite3_step(res) == SQLITE_ROW){
  //   printf("0: %s\n", sqlite3_column_text(res, 0));
  //   printf("1: %s\n", sqlite3_column_text(res, 1));
  //   printf("2: %s\n", sqlite3_column_text(res, 2));
  //   printf("3: %s\n", sqlite3_column_text(res, 3));    
  // }


  // rc = sqlite3_step(res);
  // if(rc == SQLITE_ROW){
  //   printf("%s\n", sqlite3_column_text(res, 0));
  // }
  // if(rc == SQLITE_ROW){
  //   printf("%s\n", sqlite3_column_text(res, 1));
  // }

  // END STEP TEST
  // rc = sqlite3_exec(db, sql_statement, callback, (void*)data, &zErrMsg);
  sqlite3_close(db);
  printf("EOF\n");
}
