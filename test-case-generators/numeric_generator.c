#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv) {
	intmax_t i, random, whole, fraction, num_rand;
	if (argc != 2) {
		printf("Please input the number of lines to be generated.\n");
		return -1;
	}
	num_rand = atoi(argv[1]);
	srand(time(NULL));
	for (i = 0; i < num_rand; i++) {
		random = rand();
		random = random*random*random;
		whole = random % (INTMAX_MAX>>1);
		random = rand();
		random = random*random*random;
		fraction = abs(random) % 100;
		random = rand() % 5;
		if (random == 0) {
			printf("%ju.%.2ju\n",whole,fraction);
		}
		else if (random == 1) {
			printf("%ju.00\n",whole);
		}
		else if (random ==2 ) {
			printf("-0.%.2ju\n",fraction);
		}
		else if (random == 3){
			printf("0.%.2ju\n",fraction);
		}
		else {
			printf("%ju\n",whole);
		}
	}
	return 0;
}
