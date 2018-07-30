//extremely simple makefile just as an example for later


OBJS = main.o Rectangle.o

rectPrint: $(OBJS)
	g++ --std=c++11 -o rectPrint $(OBJS)
main.o: main.cpp Rectangle.cpp
	g++ --std=c++11 -c main.cpp Rectangle.cpp
Rectangle.o:  Rectangle.hpp
	g++ --std=c++11 -c Rectangle.cpp
clean: 
	rm -f core rectPrint $(OBJS)