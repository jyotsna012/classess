#include "Media.h"

class VideoGames:public Media{

 public:
  VideoGames();
  //function to set the details of this class
  void setVideoGameDetails(float, char*);
  float* getRating();
  char* getPublisher();
  ~VideoGames();
 private:
  float* rating;
  char* publisher;
};
