#include <cstring>
#include <string.h>
#pragma once
using namespace std;
class Media{

 public:
 //functions
  Media();
  void setMediaDetails(char*,int,int);
  char* getTitle();
  int* getYear();
  int getType();
  virtual ~Media(){
    delete []title;
    delete year;
  }
 private:
 //variables
  char* title = new char[80];
  int* year = new int;
  int type;
};
