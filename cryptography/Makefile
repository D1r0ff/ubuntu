CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=#-lm
OUTPUT=crypto

# targets
all: $(OUTPUT)

$(OUTPUT): crypto.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) crypto.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

crypto.o: crypto.c crypto.h
	$(CC) $(CFLAGS) -c crypto.c $(LDLIBS) -o crypto.o

# remove compiled files
clean: 
	rm -rf $(OUTPUT) *.o
