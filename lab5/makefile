CXX = g++

CXXFLAGS = -std=c++11 -Wall

HEADERS = Animal.h AnimalState.h Cat.h Dog.h Constants.h Rat.h Utils.h Wombat.h Zoo.h

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Rat.cpp Utils.cpp Wombat.cpp Zoo.cpp

OBJS = main.o Animal.o Cat.o Dog.o Rat.o Utils.o Wombat.o Zoo.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
