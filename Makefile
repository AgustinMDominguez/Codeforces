CC = g++
CFLAGS = -Wall -Wextra -Wconversion -O2 -std=c++11
TARGET = main

all: main.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp	

base: main.cpp
	$(CC) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET)

reset: clean
	cat main.cpp >> ./Unsolved/buffer.cpp
	git checkout main.cpp
