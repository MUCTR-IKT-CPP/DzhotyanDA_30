CXX = g++

CXXFLAGS = -std=c++17 -Wall

HEADERS = catalog.h column.h commands.h identity_column.h row.h table.h value_hash.h value.h

SRCS = main.cpp catalog.cpp column.cpp commands.cpp identity_column.cpp row.cpp table.cpp value.cpp

OBJS = main.o catalog.o column.o commands.o identity_column.o row.o table.o value.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
