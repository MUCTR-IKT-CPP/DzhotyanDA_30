CXX = g++

CXXFLAGS = -std=c++11 -Wall

HEADERS = worker_generators.h worker_functions.h

SRCS = main.cpp worker_generators.cpp worker_functions.cpp worker_structs.cpp

OBJS = main.o worker_generators.o worker_functions.o worker_structs.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
