all:
	g++ -o picgen -O2 -Ofast picgen.cpp mandelbrot.cpp axis.cpp png.cpp
	g++ -o moviegen moviegen.cpp

clear:
	rm picgen
	rm moviegen
