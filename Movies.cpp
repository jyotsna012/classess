#include <iostream>
#include "Movies.h"
#include <cstring>

using namespace std;

Movies::Movies(){

}

Movies::~Movies(){
  delete []director;
  delete rating;
  delete duration;
}

//function to set details of the class
void Movies::setMovieDetails(char* newDirector, float newDuration, float newRating){
  director = new char[80];
  strcpy(director,newDirector);
  duration = new float;
  *duration = newDuration;
  rating = new float;
  *rating = newRating;

}

char* Movies::getDirector(){
  return director;
}

float* Movies::getDuration(){
  return duration;
}

float* Movies::getRating(){
  return rating;
}
