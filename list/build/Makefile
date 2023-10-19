CC = gcc
BINARY = a.exe
OBJECTS = list.o string.o main.o

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY)

string.o: ../../string/string.c
	$(CC) -c $^

%.o: ../%.c
	$(CC) -c $^

clean:
	rm *.o
