all:
	g++ -O2 -Ofast -c picgen.cpp FunIter.cpp axis.cpp png.cpp color.cpp
	ar -crv libpicgen.a picgen.o FunIter.o axis.o png.o color.o
	rm *.o

clean:
	rm *.a
