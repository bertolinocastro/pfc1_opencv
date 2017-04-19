OPENCVLIBS	= `pkg-config --libs opencv`

SOURCES 	= $(wildcard ./*.cpp)

all: main

main: $(SOURCES)
	g++ -std=c++14 $^ $(CPPFLAGS) $(OPENCVLIBS)