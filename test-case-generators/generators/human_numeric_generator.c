#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv)
{
  uintmax_t i, choice, whole, fraction, num_rand;
  int magnitude;
  char buf[1024], sign[2];
  char mag[10] = { ' ', 'k', 'K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y' };

  if (argc != 2)
    {
      printf ("Please input the number of lines to be generated.\n");
      return -1;
    }

  num_rand = atoi (argv[1]);
  srand (time (NULL));

  for (i = 0; i < num_rand; i++)
    {
      whole = (((uintmax_t) rand() << 32) | (uintmax_t) rand()) % ((INTMAX_MAX >> 5) / 10);
      fraction = abs (rand()) % 10;
      magnitude = rand() % 10;

      /* Equal chance for positive or negative. */
      if (rand() % 2 == 0)
        sprintf (sign, "");
      else
        sprintf (sign, "-");

      choice = rand() % 21;

      /* 1 in 21 chance of a zero as the whole part of the number. */
      if (choice == 0)
        {
          printf ("%s0.%ju%c\n", sign, fraction, mag[magnitude]);
        }

      /* 10 in 21 chance of non-zero whole of random length between
         1 and 16 digits and randomly chosen fraction. */
      else if (0 < choice && choice < 11)
        {
          sprintf (buf, "%ju", whole);
          printf ("%s%.*s.%ju%c\n", sign, rand() % 16 + 1, buf, fraction, mag[magnitude]);
        }

      /* 10 in 21 chance of non-zero whole of random length between
         1 and 16 digits and no fraction. */
      else
        {
          sprintf (buf, "%ju", whole);
          printf ("%s%.*s%c\n", sign, rand() % 16 + 1, buf, mag[magnitude]);
        }
    }

  return 0;
}
