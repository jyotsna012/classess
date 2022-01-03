#include <iostream>
#include "VideoGames.h"
#include <cstring>

using namespace std;

VideoGames::VideoGames(){
}

VideoGames::~VideoGames(){
  delete []publisher;
  delete rating;
}

float* VideoGames::getRating(){
  return rating;
}

//adds the information to the class Videogames
void VideoGames::setVideoGameDetails(float newRating, char* newPublisher) {
  rating = new float;
  *rating = newRating;
  publisher = new char[80];
  strcpy(publisher,newPublisher);
}

char* VideoGames::getPublisher(){
  return publisher;
}
