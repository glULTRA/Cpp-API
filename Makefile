all: compile run

compile:
	g++ *.cpp -ggdb -O2 -fomit-frame-pointer -std=c++11 -Wall -pedantic -U __STRICT_ANSI__ -DNDEBUG -o main.exe -lwinmm -lurlmon -lwininet -luuid
run:
	./main.exe