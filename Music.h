#include <iostream>
#include "Media.h"

using namespace std;
class Music:public Media{
public:
  Music();
  //sets all the deatils of the class
  void setMusicDetails(char*, float, char*);
  char* getArtist();
  float* getDuration();
  char* getPublisher();
  ~Music();
 //lists all the variables in the class
private:
  char* artist;
  float* duration;
  char* publisher;
};
