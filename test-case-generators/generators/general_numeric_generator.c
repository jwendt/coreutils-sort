#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <float.h>

int main (int argc, char** argv) {
  intmax_t i, num_rand, whole, fraction, choice;
  char sign[2];

  if (argc != 2) {
    printf("Please input the number of lines to be generated.\n");
    return -1;
  }
  num_rand = atoi(argv[1]);
  srand(time(NULL));
  for (i = 0; i < num_rand; i++) {
    whole = rand()*rand()*rand();
    fraction = rand()*rand()*rand();

    choice = rand() % 2;
    if (choice == 0) {
      sprintf(sign,"");
    }
    else {
      sprintf(sign,"-");
    }

    choice = rand() % 3;
    if (choice == 0) {
      printf("%s%ju.%ju\n",sign,whole,fraction);
    }
    else if (choice == 1) {
      printf("%s%ju\n",sign,whole);
    }
    else {
      printf("%s0.%ju\n",sign,fraction);
    }
  }
  return 0;
}
