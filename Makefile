all:helloworld

hello: hello.o
	g++ -std=c++11 -c hello hello.o

hello.o: helloworld.cpp
	g++ -std=c++11 -o hello.cpp