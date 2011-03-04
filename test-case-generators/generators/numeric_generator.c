#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv) {
	intmax_t i, random, whole, fraction, num_rand;
    char buf[1024];
	if (argc != 2) {
		printf("Please input the number of lines to be generated.\n");
		return -1;
	}
	num_rand = atoi(argv[1]);
	srand(time(NULL));
	for (i = 0; i < num_rand; i++) {
		random = rand();
		random = random*random;
		whole = random % (INTMAX_MAX>>1);
		random = rand();
		random = random*random*random;
		fraction = abs(random) % 100;
		random = rand() % 7;
		if (random == 0) {
            sprintf(buf,"%ju",whole);
			printf("%.*s.%ju\n",rand()%20+1,buf,fraction);
		}
		else if (random == 1) {
            sprintf(buf,"%ju",whole);
            printf("-%.*s.%ju\n",rand()%20+1,buf,fraction);
        }
		else if (random == 2) {
            sprintf(buf,"%ju",whole);
			printf("%.*s.00\n",rand()%20+1,buf);
		}
		else if (random == 3) {
			printf("-0.%.2ju\n",fraction);
		}
		else if (random == 4){
			printf("0.%.2ju\n",fraction);
		}
		else if (random == 5) {
            sprintf(buf,"%ju",whole);
            printf("-%.*s\n",rand()%20+1,buf);
        }
		else {
            sprintf(buf,"%ju",whole);
			printf("%.*s\n",rand()%20+1,buf);
		}
	}
	return 0;
}
