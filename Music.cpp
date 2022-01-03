#include <iostream>
#include "Music.h"
#include <cstring>

using namespace std;

Music::Music(){

}

char* Music::getPublisher(){
  return publisher;
}

char* Music::getArtist(){
  return artist;
}

float* Music::getDuration(){
  return duration;
}

//function to delete the class
Music::~Music(){
  delete []artist;
  delete []publisher;
  delete duration;
}
//function to set details of the class
void Music::setMusicDetails(char* newArtist, float newDuration, char* newPublisher){
  artist = new char[80];
  strcpy(artist,newArtist);
  duration = new float;
  *duration = newDuration;
  publisher = new char[80];
  strcpy(publisher,newPublisher);
}
