all:
	g++ -O2 -Ofast -c picgen.cpp FunIter.cpp axis.cpp png.cpp color.cpp GMP_Wrapper.cpp
	ar -crv libpicgen.a picgen.o FunIter.o axis.o png.o color.o GMP_Wrapper.o
	rm *.o

clean:
	rm *.a
