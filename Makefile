# Makefile Projet
CFLAGS = -ansi -Wall -lMLV

myMemory: bin/main.o bin/argument.o bin/fifo.o bin/lru.o bin/deuxiemeChance1.o bin/deuxiemeChance2.o bin/structure.o
	gcc -o myMemory bin/main.o bin/argument.o bin/fifo.o bin/lru.o bin/deuxiemeChance1.o bin/deuxiemeChance2.o bin/structure.o $(CFLAGS)

bin/argument.o: ./src/argument.c ./include/argument.h ./include/structure.h ./include/fifo.h ./include/lru.h ./include/deuxiemeChance1.h ./include/deuxiemeChance2.h
	gcc -c ./src/argument.c $(CFLAGS) -o bin/argument.o

bin/fifo.o: ./src/fifo.c ./include/fifo.h ./include/structure.h
	gcc -c ./src/fifo.c $(CFLAGS) -o bin/fifo.o

bin/lru.o: ./src/lru.c ./include/lru.h ./include/structure.h
	gcc -c ./src/lru.c $(CFLAGS) -o bin/lru.o

bin/deuxiemeChance1.o: ./src/deuxiemeChance1.c ./include/deuxiemeChance1.h ./include/structure.h
	gcc -c ./src/deuxiemeChance1.c $(CFLAGS) -o bin/deuxiemeChance1.o

bin/deuxiemeChance2.o: ./src/deuxiemeChance2.c ./include/deuxiemeChance2.h ./include/structure.h ./include/deuxiemeChance1.h
	gcc -c ./src/deuxiemeChance2.c $(CFLAGS) -o bin/deuxiemeChance2.o

bin/structure.o: ./src/structure.c ./include/structure.h 
	gcc -c ./src/structure.c $(CFLAGS) -o bin/structure.o

bin/main.o: src/main.c ./include/argument.h ./include/fifo.h ./include/lru.h ./include/deuxiemeChance1.h ./include/deuxiemeChance2.h ./include/structure.h
	gcc -c src/main.c $(CFLAGS) -o bin/main.o

clean:
	-rm bin/*.o
	-rm myMemory