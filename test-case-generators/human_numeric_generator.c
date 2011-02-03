#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv) {
	intmax_t i, random, whole, fraction, num_rand;
	int magnitude;
	char mag[10] = { ' ', 'k', 'K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y' };
	if (argc != 2) {
		printf("Please input the number of lines to be generated.\n");
		return -1;
	}
	num_rand = atoi(argv[1]);
	srand(time(NULL));
	for (i = 0; i < num_rand; i++) {
		random = rand();
		random = random*random*random;
		whole = random % (INTMAX_MAX>>5);
		random = rand();
		random = random*random*random;
		fraction = abs(random) % 100;
		magnitude = rand() % 10;
		random = rand() % 5;
		if (random == 0) {
			printf("%ju.%.1ju%c\n",whole,fraction,mag[magnitude]);
		}
		else if (random == 1) {
			printf("%ju.0%c\n",whole,mag[magnitude]);
		}
		else if (random ==2 ) {
			printf("-0.%.1ju%c\n",fraction,mag[magnitude]);
		}
		else if (random == 3){
			printf("0.%.1ju%c\n",fraction,mag[magnitude]);
		}
		else {
			printf("%ju%c\n",whole,mag[magnitude]);
		}
	}
	return 0;
}
