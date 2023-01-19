all:hello questions_3

hello: hello.o 
	g++ -std=c++11 -o hello hello.o

questions_3: questions_3.o
	g++ -std=c++11 -o questions_3 questions_3.o

hello.o: hello.cpp
	g++ -std=c++11 -c hello.cpp

questions_3.o: questions_3.cpp
	g++ -std=c++11 -c questions_3.cpp

user_io.o: user_io.cpp image_menu.h
	g++ -std=c++11 -o user_io.cpp

controllers.o: controllers.cpp image_menu.h
	g++ -std=c++11 -o controller.cpp


