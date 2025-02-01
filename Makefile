CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -pedantic -g
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = Universe.hpp CelestialBody.hpp
OBJS = main.o Universe.o CelestialBody.o

all: NBody NBody.a test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

NBody: $(OBJS)
	$(CC) $(CFLAGS) -o NBody $(OBJS) $(LIBS)

NBody.a: $(OBJS)
	ar rcs NBody.a $(OBJS)

test: test.o Universe.o CelestialBody.o
	$(CC) $(CFLAGS) -o test test.o Universe.o CelestialBody.o $(LIBS)

clean:
	rm -f NBody NBody.a test *.o

lint:
	cpplint *.cpp *.hpp
