all:
	g++ -o test -O2 -Ofast main.cpp mandelbrot.cpp axis.cpp png.cpp
	g++ -o paperpicgen paperpicgen.cpp

clear:
	rm test
	rm paperpicgen
