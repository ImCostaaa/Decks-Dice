using namespace std;
#include "LeaderBoard.h"



//Constructor For leaderBoard 
LeaderBoard::LeaderBoard(){

//Read Data from file, Ignore login info
  ifstream file;
  string line;
  file.open(USER_DATA);

//Ignore the login info
  while(getline(file,line)){
    if(line.find("LOGIN") != -1){
      while(getline(file,line)){
        if(line.find(",") != -1){continue;}
        else{break;}}}

//push everything else on vector
     highscores.push_back(line);}}

//View all highscores,Loop through vector
void LeaderBoard::view_highscores(){
  int count = highscores.size();
  cout<<"All Highscores:"<<endl;
  for(int i =0;i<count;i++){
    cout<< highscores.at(i) <<endl;}
  cout<<"\n"<<endl;
}

//View all highscores for a specific player
void LeaderBoard::view_player(string name){
 string user = name;
 int count = highscores.size();
 cout<<user+"'s Highscores"<<endl;
 for(int i=0;i<count;i++){
//Check for username in all the data lines and show if matches
  string line =highscores.at(i);
  size_t pos = line.find(",");
//Split string by the first comma found
  string username = line.substr(0,pos);
  if(line.find(",")==-1)cout<<line<<endl;
  if(pos != -1 && username.compare(user) == 0)cout<<line<<endl;}
}

