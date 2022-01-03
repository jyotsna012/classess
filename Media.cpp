#include <iostream>
#include "Media.h"
#include <string.h>
#include <cstring>

using namespace std;

Media::Media(){
}

//function to set details of the class
void Media::setMediaDetails(char* newTitle,int newYear,int set){
  strcpy(title,newTitle);
  *year = newYear;
  type = set;
}

//functions to get details of the class
char* Media::getTitle(){
  return title;
}

int* Media::getYear(){
  return year;
}

int Media::getType(){
  return type;
}
