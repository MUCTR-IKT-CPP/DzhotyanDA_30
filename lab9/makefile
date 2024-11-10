CXX = g++

CXXFLAGS = -std=c++11 -Wall

HEADERS = NaturalNumberDivisors.h

SRCS = main.cpp NaturalNumberDivisors.cpp

OBJS = main.o NaturalNumberDivisors.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
