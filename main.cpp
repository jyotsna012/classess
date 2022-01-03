//jyotsna tera. Dec 2021
// Media project
//uses classes and vectors to create a database where user can add, find, and delete media items
#include <iostream>
#include <cstring>
#include "Media.h"
#include "VideoGames.h"
#include <vector>
#include "Music.h"
#include "Movies.h"

using namespace std;

//initalize the functions
void addD(vector<Media*> &storage);
void searchD(vector<Media*> storage);
void deleteD(vector<Media*> &storage);

//Start up message that asks user what to do
int main(){
  vector<Media*> media;
  char input[80];
  while (true){
    cout << "enter an action: add, search, delete, or quit" << endl;
    cout << "enter 1 for Add" << endl;
    cout << "enter 2 for Search" << endl;
    cout << "enter 3 for Delete" << endl;
    cout << "enter 4 for Quit" << endl;

    cin >> input;
    cin.get();
    if(input[0]=='1'){
      addD(media);
    }
    else if(input[0]=='2'){
      searchD(media);
    }
    else if(input[0]=='3'){
      deleteD(media);
    }
    else if(input[0]=='4'){
      break;
    }
  }
  return 0;
  
  
}

//search function
void searchD(vector<Media*> storage){

  cout << "would you like to search using the title or the year?" << endl;
  cout << "Enter 't' for title or 'y' for year" << endl;
  char input[10];
  cin >> input;
  cin.get();
  int year;
  char title[80];
 if(input[0]=='y'){
    cout << "please enter the year" << endl;
    cin >> year;
    cin.get();
 }
 else if(input[0]=='t'){
    cout << "please enter the title" << endl;
    cin.get(title,80);
    cin.get();
 }
    //iterates through vector and checks for any that have matches to what user entered
    for(vector<Media*>::iterator it = storage.begin(); it!=storage.end(); it++){
      if(*((*it)->getYear())==year || strcmp(((*it)->getTitle()),title)==0){
	//finds the type of the match
	int typeOfMedia = (*it)->getType();
	if(typeOfMedia == 1){ //videogame
		//lists out all the information stored
		cout<<"Title: "<<(*it)->getTitle()<<endl;
		cout<<"Year: "<< *(*it)->getYear() << endl;
		cout<<"Publisher: "<<(dynamic_cast<VideoGames*>(*it))->getPublisher() << endl; 
		cout<<"Rating: "<<*(dynamic_cast<VideoGames*>(*it))->getRating()<<endl;
		cout<<"<--------------->"<< endl;
        }  
	if(typeOfMedia == 2){ //music
		//lists out all the information stored
		cout<<"Title: "<<(*it)->getTitle()<<endl;
		cout<<"Year: "<< *(*it)->getYear() << endl;
		cout<<"Artist: "<<(dynamic_cast<Music*>(*it))->getArtist()<< endl;
		cout<<"Duration: "<<(dynamic_cast<Music*>(*it))->getDuration()<< endl;
		cout<<"Publisher: "<<(dynamic_cast<Music*>(*it))->getPublisher()<< endl;
		cout<<"<--------------->"<< endl;
	}
	if(typeOfMedia == 3){ //movie
		//lists out all the information stored
		cout<<"Title: "<<(*it)->getTitle()<<endl;
		cout<<"Year: "<< *(*it)->getYear() << endl;
		cout<<"Director: "<<(dynamic_cast<Movies*>(*it))->getDirector()<< endl;
		cout<<"Duration: "<<(dynamic_cast<Movies*>(*it))->getDuration()<< endl;
		cout<<"Rating: "<<*(dynamic_cast<Movies*>(*it))->getRating()<< endl;
		cout<<"<--------------->"<< endl;
      }   
    }
  }
}

//function to delete
void deleteD(vector<Media*> &storage){
  //asks the user how they would like to indentify what to delete
  cout << "would you like to search using the title or the year?" << endl;
  cout << "Enter 't' for title or 'y' for year" << endl;
  char input[10];
  cin >> input;
  cin.get();
  int year;
  char title[80];
 if(input[0]=='y'){
    cout << "please enter the year" << endl;
    cin >> year;
    cin.get();
 }
 else if(input[0]=='t'){
    cout << "please enter the title" << endl;
    cin.get(title,80);
    cin.get();
 }
    //loops through vector until match is found.
    for(vector<Media*>::iterator it = storage.begin(); it!=storage.end(); it++){
      if(*((*it)->getYear())==year || strcmp(((*it)->getTitle()),title)==0){
	int typeOfMedia = (*it)->getType();
	if(typeOfMedia == 1){ //videogame
		//prints out information about the media
		cout<<"Title: "<<(*it)->getTitle()<<endl;
		cout<<"Year: "<< *(*it)->getYear() << endl;
		cout<<"Publisher: "<<(dynamic_cast<VideoGames*>(*it))->getPublisher() << endl; 
		cout<<"Rating: "<<*(dynamic_cast<VideoGames*>(*it))->getRating()<<endl;
		cout<<"<--------------->"<< endl;
        }  
	if(typeOfMedia == 2){ //music
		//prints out information about the media
		cout<<"Title: "<<(*it)->getTitle()<<endl;
		cout<<"Year: "<< *(*it)->getYear() << endl;
		cout<<"Artist: "<<(dynamic_cast<Music*>(*it))->getArtist()<< endl;
		cout<<"Duration: "<<(dynamic_cast<Music*>(*it))->getDuration()<< endl;
		cout<<"Publisher: "<<(dynamic_cast<Music*>(*it))->getPublisher()<< endl;
		cout<<"<--------------->"<< endl;
	}
	if(typeOfMedia == 3){ //movie
		//prints out information about the media
		cout<<"Title: "<<(*it)->getTitle()<<endl;
		cout<<"Year: "<< *(*it)->getYear() << endl;
		cout<<"Director: "<<(dynamic_cast<Movies*>(*it))->getDirector()<< endl;
		cout<<"Duration: "<<(dynamic_cast<Movies*>(*it))->getDuration()<< endl;
		cout<<"Rating: "<<*(dynamic_cast<Movies*>(*it))->getRating()<< endl;
		cout<<"<--------------->"<< endl;
      }   
    }
      //asks the user if they would like to delete the printed media
     cout << "do you want to delete the above video game? (y/n)?" << endl;
     char yn[2];
     cin>>yn;
     cin.get();
	    
	    
     if(yn[0]=='y'){
	  storage.erase(it);
	  delete(dynamic_cast<VideoGames*>(*it));
	  return;
     }else{
	  cout << "okay, not deleting" << endl;
     }
  }
}

//function to add
void addD(vector<Media*> &storage){
  char input1[80];
  //asks what type of media to add
  cout << "Enter what type you would like to add: Movie, Music, VideoGame" << endl;
  cout << "Enter 1 for VideoGame" << endl;
  cout << "Enetr 2 for Music" << endl;
  cout << "Enetr 3 for Movie" << endl;
  cin.get(input1,80);
  cin.get();
 
  //asks for title and year of media regardless of what type
  cout << "Enter the title" << endl;
  char title[80];
  cin.get(title,80);
  cin.get();
  cout << "Enter the year" << endl;
  int year;
  cin >> year;
  cin.get();
	
  //based on the type of media, askes the specific questions	
  if(input1[0]== '1'){
    VideoGames* vc= new VideoGames();
    cout << "Enter the publisher" << endl;
    char publisher[80];
    cin.get(publisher,80);
    cin.get();
    cout << "Enter the star rating" << endl;
    float rating;
    cin >> rating;
    cin.get();
    //adds all the information to the class
    vc->setMediaDetails(title, year, 1);
    vc->setVideoGameDetails(rating, publisher);
    //adds the class to the vector
    storage.push_back(vc);
  }
  else if(input1[0]== '2'){
    Music* m = new Music();
    m->setMediaDetails(title, year, 2);
    cout << "Enter the artist's name" << endl;
    char artist[80];
    cin.get(artist,80);
    cin.get();
    cout << "Enter the duration in seconds" << endl;
    float duration;
    cin >> duration;
    cin.get();
    cout << "Enter the publisher" << endl;
    char publisher[80];
    cin.get(publisher,80);
    cin.get();
    //adds all the information to the class
    m->setMusicDetails(artist,duration,publisher);
    //adds the class to the vector
    storage.push_back(m);
  }
  else if(input1[0]== '3'){
    Movies* mo = new Movies();
    mo->setMediaDetails(title, year, 3);
    cout << "Enter the director's name" << endl;
    char director[80];
    cin.get(director,80);
    cin.get();
    cout << "Enter the duration in minutes" << endl;
    float duration;
    cin >> duration;
    cin.get();
    cout << "Enter the star rating" << endl;
    float rating;
    cin >> rating;
    cin.get();
    //adds all the information to the class
    mo->setMovieDetails(director,duration,rating);
    //adds the class to the vector
    storage.push_back(mo);
  }
  else{
    cout << "Error, try again" << endl;
    return;
  }
		     
}
