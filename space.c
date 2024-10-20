#include <stdio.h>

int main() {

  double earthWeight;
  int planetSelection;
  char buffer[32];

  printf("Please enter your current earth weight: ");
  fgets(buffer, 32, stdin);
  sscanf(buffer, "%lf", &earthWeight);

  printf("\n\tPlanet List!\n\t[1]Mercury\n\t[2]Venus\n\t[3]Mars\n\t[4]Jupiter\n\t[5]Saturn\n\t[6]Uranus\n\t[7]Neptune\n");
  printf("Please enter a number for a planet here: ");
  fgets(buffer, 32, stdin);
  sscanf(buffer, "%d", &planetSelection);

  switch(planetSelection) {
  case 1:
    earthWeight *= 0.38;
    break;
  case 2:
    earthWeight *= 0.91;
    break;
  case 3:
    earthWeight *= 0.38;
    break;
  case 4:
    earthWeight *= 2.34;
    break;
  case 5:
    earthWeight *= 1.06;
    break;
  case 6:
    earthWeight *= 0.92;
    break;
  case 7:
    earthWeight *= 1.19;
    break;
  default:
    printf("Invalid selection, off to gulag for you");
    break;
  }

  printf("Your weight: %lf\n", earthWeight);
  return 0;
}
