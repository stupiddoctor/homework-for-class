all: Chicken.exe
Chicken.exe: Chicken.o
	g++ Chicken.o -o Chicken.exe 
Chicken.o: Chicken.cpp
	g++ -c Chicken.cpp -o Chicken.o
clean:
	rm -f Chicken.exe Chicken.o

.PHONY: all clean

