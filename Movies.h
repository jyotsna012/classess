#include "Media.h"

using namespace std;
class Movies:public Media{
 public:
 //functions
  Movies();
  void setMovieDetails(char*, float, float);
  char* getDirector();
  float* getDuration();
  float* getRating();
  ~Movies();
 //variables
 private:
  char* director;
  float* duration;
  float* rating;
};
