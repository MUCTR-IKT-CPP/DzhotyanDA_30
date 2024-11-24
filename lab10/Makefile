CXX = g++

CXXFLAGS = -std=c++17 -Wall

HEADERS = Catalog.h Table.h Row.h Column.h Value.h DataTypes.h

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
