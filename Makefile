CStackRunner: CData.o CStack.o main.o
	wg++ -fno-elide-constructors -std=c++11 CData.o CStack.o main.o

main.o: main.cpp CStack.h CData.h
	wg++ -fno-elide-constructors -std=c++11  main.cpp -c

CStack.o: CStack.cpp CStack.h
	wg++ -fno-elide-constructors -std=c++11  CStack.cpp -c

#CData.o: CData.cpp CData.h
	#wg++ -fno-elide-constructors -std=c++11  CData.cpp -c