#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Race {
  int numLaps;
  int currentLap;
  char firstPlaceDriverName[20];
  char firstPlaceCarColour[20];
};


struct RaceCar {
  char driverName[20];
  char carColour[20];
  int totalLapTime;
};


void printIntro() {
  printf("Welcome to this Formula C digital race event\nSit down and grab your popcorn as the race is about to begin!\n\n");
}

void countdown(){
  printf("Racers Ready! In...\n");
  for(int i = 5; i >= 0; i--){
    if (i == 0){
      printf("Race!\n");
    } else {
      printf("%d\n", i);
    }
  }
}


void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %d\nFirst place is %s in the %s car!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceCarColour);

}


void printCongrats(struct Race race) {
  printf("Lets all congratulate %s in the %s car for a sensational performance!\nIt was a great race and everyone have a goodnight!\n", race.firstPlaceDriverName, race.firstPlaceCarColour);
}


int calculateTimeToCompleteLap(){
  int speed, accel, nerves = (rand()%3)+1;
  int san = speed + accel + nerves;
  
  return san;
}


void updateRaceCar(struct RaceCar* raceCar) { 
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}


void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  //I kinda have an issue with this logic being that if == always car1, fix
  if(raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceCarColour, raceCar1->carColour);
  } else { //quick and dirty
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceCarColour, raceCar2->carColour);
  }
}


void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5,1,"",""}; //Instantiate a Race to use in for loop
  for(int lap = 0; lap < race.numLaps; lap++){
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap++;
  }
  printCongrats(race);
}


int main() {
	srand(time(0));
  printIntro();
  countdown();
  struct RaceCar raceCar1 = {"Alice", "Red", 0};
  struct RaceCar raceCar2 = {"Bob", "Blue", 0};
  startRace(&raceCar1, &raceCar2); //pass memory addr to pointer type
};