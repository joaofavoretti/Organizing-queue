COMPILER = gcc
MAIN = main.c
PROG = main
FUNCTIONS = Functions/state-functions.c Functions/IO-Operations.c Functions/queue-Operations.c Functions/queue-Setup.c
HEADERS = Includes
OBJECTS = main.o IO-Operations.o queue-Operations.o queue-Setup.o state-functions.o


compile: $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $(PROG)
	
run:
	./$(PROG)


all:
	$(COMPILER) $(MAIN) $(FUNCTIONS) -I $(HEADERS) -o $(PROG)

debug:
	$(COMPILER) $(MAIN) $(FUNCTIONS) -I $(HEADERS) -o $(PROG) -g

IO-Operations.o: Functions/IO-Operations.c Includes/main.h
	$(COMPILER) -c -O Functions/IO-Operations.c -I $(HEADERS) -o IO-Operations.o

queue-Operations.o: queue-Operations.c Includes/main.h
	$(COMPILER) -c -O queue-Operations.c -I $(HEADERS) -o queue-Operations.o

queue-Setup.o: Functions/queue-Setup.c Includes/main.h
	$(COMPILER) -c -O Functions/queue-Setup.c -I $(HEADERS) -o queue-Setup.o

state-functions.o: Functions/state-functions.c Includes/main.h
	$(COMPILER) -c -O Functions/state-functions.c -I $(HEADERS) -o state-functions.o

main.o: main.c Includes/main.h
	$(COMPILER) -c -O main.c -I $(HEADERS) -o main.o


clean:
	rm *.o $(PROG)
