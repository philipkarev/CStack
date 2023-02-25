CStackRunner: CStack.o main.o
	wg++ -fno-elide-constructors -std=c++11 CStack.o main.o

main.o: main.cpp CStack.h
	wg++ -fno-elide-constructors -std=c++11  main.cpp -c

CStack.o: CStack.cpp CStack.h
	wg++ -fno-elide-constructors -std=c++11  CStack.cpp -c