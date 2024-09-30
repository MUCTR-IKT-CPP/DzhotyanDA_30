CXX = g++

CXXFLAGS = -std=c++11 -Wall

HEADERS = characters.h guild.h

SRCS = main.cpp characters.cpp guild.cpp

OBJS = main.o characters.o guild.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
