CC = gcc
BINARY = a.exe
OBJECTS = point.o main.o

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY)

%.o: ../%.c
	$(CC) -c $^

clean:
	rm *.o
	rm $(BINARY)
