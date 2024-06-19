all: test.cpp lib/libpicgen.a
	g++ test.cpp -Llib -lpicgen -lgmp -fopenmp -fext-numeric-literals -I src/ -o test -O2 -Ofast -std=c++20

lib/libpicgen.a: src/*.h src/*.cpp
	cd src && make
	mv src/libpicgen.a lib/libpicgen.a