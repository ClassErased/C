#include <stdio.h>
#include <stdbool.h>

int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int year) {
  //Rememember non-zero = true, ie (year%100 = true if remainder)
  return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

void addDaysToDate(int* dd, int* mm, int* year, int daysLeftToAdd) {
  int daysLeftInMonth;
  while(daysLeftToAdd > 0){
    daysLeftInMonth = daysInMonth[*mm] - *dd;
    if(isLeapYear(*year) && *mm == 2){
      daysLeftInMonth++;
    }
  if(daysLeftToAdd > daysLeftInMonth){
    daysLeftToAdd -= (daysLeftInMonth + 1);
    *dd = 1;
    if(*mm == 12){
      *mm = 1;
      (*year)++;
    } else {
        *mm = *mm + 1;
    }
  } else {
    *dd = *dd + daysLeftToAdd;
    daysLeftToAdd = 0;
  }
  }
}

int main() {
  int dd, mm, year, daysLeftToAdd;
  printf("Please enter a date (dd mm yyyy) and the number of days to add to the date:\t");
  scanf("%d%d%d%d", &dd, &mm, &year, &daysLeftToAdd); //unsafe lol
  addDaysToDate(&dd, &mm, &year, daysLeftToAdd);
  printf("%d/%d/%d", dd, mm, year);
}

//TODO: input validation and fix hanging if no days to add