#include <iostream>
#include <sqlite3.h>

int main(){
  sqlite3 *db;
  int rc;

  std::string db_path = "/tmp/kjv.db";
  rc = sqlite3_open(db_path.c_str(), &db);

  if(rc){
    fprintf(stderr, "Cant open database: %s\n", sqlite3_errmsg(db));
  }else{
    printf("Opened database ok: %s\n", db_path.c_str());
  }

  sqlite3_close(db);
  printf("EOF\n");
}
