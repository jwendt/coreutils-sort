all: general_numeric_generator human_numeric_generator \
	numeric_generator

general_numeric_generator.o: general_numeric_generator.c
	gcc -c general_numeric_generator.c

general_numeric_generator: general_numeric_generator.o
	gcc general_numeric_generator.o -o general_numeric_generator

human_numeric_generator.o: human_numeric_generator.c
	gcc -c human_numeric_generator.c

human_numeric_generator: human_numeric_generator.o
	gcc human_numeric_generator.o -o human_numeric_generator

numeric_generator.o: numeric_generator.c
	gcc -c numeric_generator.c

numeric_generator: numeric_generator.o
	gcc numeric_generator.o -o numeric_generator

clean:
	/bin/rm -f *.o
	/bin/rm -f general_numeric_generator
	/bin/rm -f human_numeric_generator
	/bin/rm -f numeric_generator
