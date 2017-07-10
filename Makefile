CFLAGS=-Wall -DNDEBUG -g

all:
	make ex1 ex3

clean:
	rm -f ex1 ex3

t_ex19:
	rm ex19
	make ex19
