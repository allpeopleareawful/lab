CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = 25-26.cpp queueDynamic.h
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = queue.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@