#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <float.h>

int main (int argc, char** argv) {
	intmax_t i, num_rand;


	double x;
	double random;
	int choice;

	if (argc != 2) {
		printf("Please input the number of lines to be generated.\n");
		return -1;
	}
	num_rand = atoi(argv[1]);
	srand(time(NULL));
	for (i = 0; i < num_rand; i++) {
		//printf("random=%d\n",random);
		//printf("DBL_MIN=%jf\n",DBL_MIN);
		//printf("DBL_MAX=%jf\n",DBL_MAX);


		random = ((double)rand() )/ (RAND_MAX+1);

		choice = rand() % 2;


		//printf("random=%f\n",random);
		//printf("choice=%d\n",choice);

		if (choice == 0)
			x = random*1;
		else
			x = random*((double)DBL_MAX);

		choice = rand() % 2;
		if (choice == 0)
			x *= -1;


		printf("%jf\n",x);
		/*
		random = random*random*random;
		whole = random % INTMAX_MAX;
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
		}*/
	}
	return 0;
}