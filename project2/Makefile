CC = gcc
CFLAGS = -Wall
TARGET = p2

all: $(TARGET)

$(TARGET): cmsc257-p2.o p2-support.o
	$(CC) $(CFLAGS) -o $(TARGET) cmsc257-p2.o p2-support.o

cmsc257-p2.o: cmsc257-p2.c p2-support.h
	$(CC) $(CFLAGS) -c cmsc257-p2.c

p2-support.o: p2-support.c p2-support.h
	$(CC) $(CFLAGS) -c p2-support.c

clean:
	rm -f *.o $(TARGET)
