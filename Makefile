all: test.cpp lib/libpicgen.a
	mpicxx test.cpp -Llib -lpicgen -lgmp -fopenmp -I src/ -o test -O2 -Ofast

lib/libpicgen.a: src/*.h src/*.cpp
	cd src && make
	mv src/libpicgen.a lib/libpicgen.a