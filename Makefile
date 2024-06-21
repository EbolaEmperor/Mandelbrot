all: test.cpp libpicgen.a
	mpicxx test.cpp -L. -lpicgen -lgmp -fopenmp -I src/ -o test -O2 -Ofast

libpicgen.a: src/*.h src/*.cpp
	cd src && make
	mv src/libpicgen.a libpicgen.a

clean:
	rm libpicgen.a test