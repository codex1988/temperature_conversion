// The next program uses the formula C = (5 / 9)(F - 32) to print the
// following table of Fahrenheit temperatures and their centigrade or Celsius
// equivalents.
// Exercise 1.15. Rewrite the temperature conversion program of Section 1.2
// to use a function for conversion.

#include <stdio.h>

#define STEP 20    // a step between values
#define LENGTH 16  // the length of an array (relevant to an upper bound)

int convert(int degree[], char unit);

int main(void) {
  int i;
  float t;
  int degree[LENGTH];
  int temp = STEP;

  for (i = 0; i < LENGTH; ++i) {
    if (i == 0) {
      degree[i] = 0;
      continue;
    } else if (i == 1) {
      degree[i] = temp;
    } else {
      degree[i] = temp + STEP;
      temp += STEP;
    }
  }

  convert(degree, 'f');

  return 0;
}

int convert(int degree[], char unit) {
  int i;
  int t;
  if (unit == 'c') {
    printf("  C  =>  F\n");
    for (i = 0; i < LENGTH; ++i) {
      t = (9.0 * degree[i] / 5.0) + 32.0;
      printf("%3d  => %3d\n", degree[i], t);
    }
    return 0;
  } else if (unit == 'f') {
    printf("  F  =>  N\n");
    for (i = 0; i < LENGTH; ++i) {
      t = (5.0 / 9.0) * (degree[i] - 32.0);
      printf("%3d  => %3d\n", degree[i], t);
    }
    return 0;
  } else {
    printf("Invalid unit. Use \'c\' or \'f\'.\n");
    return 1;
  }
}
