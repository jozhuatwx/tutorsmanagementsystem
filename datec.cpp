#include <time.h>
#include "datec.h"

time_t intToTime(int day, int month, int year) {
  // initialise
  tm date;
  time_t now = time(0);
  localtime_s(&date, &now);
  // change date to user input date
  date.tm_mday = day;
  // tm month measures from 0
  date.tm_mon = month - 1;
  // tm year measures from 1900
  date.tm_year = year - 1900;
  return mktime(&date);
};

bool validateDate(int day, int month, int year) {
  // to ensure the date is valid
  if (year >= 1970 && year < 3000 && day >= 1 && month >= 1) {
    // to ensure number of days is valid
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
      if (day <= 31)
        return true;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day <= 30)
        return true;
    } else if (month == 2) {
      // to account for leap years
      if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        if (day <= 29)
          return true;
      } else {
        if (day <= 28)
          return true;
      };
    };
  };
  return false;
};
