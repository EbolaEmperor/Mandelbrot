all:
	g++ test.cpp -Llib -lpicgen -I src/ -o test -O2 -Ofast