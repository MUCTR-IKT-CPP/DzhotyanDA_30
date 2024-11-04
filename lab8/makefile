CXX = g++

CXXFLAGS = -std=c++11 -Wall

HEADERS = Gun.h Magazine.h Patron.h Constants.h SubsonicPatron.h SupersonicPatron.h TracingPatron.h

SRCS = main.cpp Magazine.cpp Patron.cpp SubsonicPatron.cpp SupersonicPatron.cpp TracingPatron.cpp

OBJS = main.o Magazine.o Patron.o SubsonicPatron.o SupersonicPatron.o TracingPatron.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
