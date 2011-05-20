#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <float.h>

int main (int argc, char** argv)
{
  uintmax_t i, num_rand, whole, fraction, choice;
  char sign[2];

  if (argc != 2)
    {
      printf ("Please input the number of lines to be generated.\n");
      return -1;
    }

  num_rand = atoi (argv[1]);

  srand (time (NULL));

  for (i = 0; i < num_rand; i++)
    {
      whole = ( (uintmax_t) rand() << 32) | (uintmax_t) rand();
      fraction = ( (uintmax_t) rand() << 32) | (uintmax_t) rand();

      /* Equal chance of positive or negative. */
      if (rand() % 2 == 0)
        sprintf (sign, "");
      else
        sprintf (sign, "-");

      choice = rand() % 3;

      /* 1 in 3 chance of a whole and a fraction. */
      if (choice == 0)
        printf ("%s%ju.%ju\n", sign, whole, fraction);
      /* 1 in 3 chance of a whole and no fraction. */
      else if (choice == 1)
        printf ("%s%ju\n", sign, whole);
      /* 1 in 3 chance of no whole and a fraction. */
      else
        printf ("%s0.%ju\n", sign, fraction);
    }

  return 0;
}
