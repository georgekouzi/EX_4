
CC     = gcc
FLAGS = -Wall -Werror -g
DEPSF = frequency.o main.o
DEPS     =  frequency.h


all: frequency

frequency: $(DEPSF)
	$(CC) $(FLAGS) $^ -o $@

main.o: main.c $(DEPS)
	$(CC) -c $(FLAGS) $<
	
frequency.o: frequency.c $(DEPS)
	$(CC) -c $(FLAGS) $<

.PHONY: 
	clean  all
clean:
	rm  *$(DEPSF) frequency