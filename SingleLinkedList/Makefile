all: SingleLinkedList.exe
SingleLinkedList.exe: SingleLinkedList.o
	g++ SingleLinkedList.o -o SingleLinkedList.exe 
SingleLinkedList.o: SingleLinkedList.cpp
	g++ -c SingleLinkedList.cpp -o SingleLinkedList.o
clean:
	rm -f SingleLinkedList.exe SingleLinkedList.o
.PHONY: all clean
