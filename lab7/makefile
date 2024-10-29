CXX = g++

CXXFLAGS = -std=c++11 -Wall

HEADERS = Vector.h

SRCS = main.cpp

OBJS = main.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
