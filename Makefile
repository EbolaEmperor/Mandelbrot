all:
	g++ -o picgen -O2 -Ofast picgen.cpp mandelbrot.cpp axis.cpp png.cpp color.cpp
	g++ -o moviegen moviegen.cpp axis.cpp

clear:
	rm picgen
	rm moviegen
