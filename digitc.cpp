#include "digitc.h"

int countDigits(int number) {
  int digits = 0;
  int temp = number;

  while (temp != 0) {
    digits++;
    temp /= 10;
  };
  return digits;
};
