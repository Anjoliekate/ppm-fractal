all:hello questions_3 ascii_image

hello: hello.o 
	g++ -std=c++11 -o hello hello.o

hello.o: hello.cpp
	g++ -std=c++11 -c hello.cpp

#Questions 3

questions_3: questions_3.o user_io.o
	g++ -std=c++11 -o questions_3 questions_3.o

questions_3.o: questions_3.cpp image_menu.h
	g++ -std=c++11 -c questions_3.cpp

user_io.o: user_io.cpp image_menu.h
	g++ -std=c++11 -c user_io.cpp

controllers.o: controllers.cpp image_menu.h
	g++ -std=c++11 -c controllers.cpp

#  Ascii Image

ascii_image: ascii_image.o Image.o controllers.o image_drawing.o image_output.o user_io.o 
	g++ -std=c++11 -o ascii_image ascii_image.o Image.o controllers.o image_drawing.o image_output.o user_io.o

ascii_image.o: ascii_image.cpp image_menu.h Image.h
	g++ -std=c++11 -c ascii_image.cpp

image_drawing.o: image_drawing.cpp image_menu.h Image.h
	g++ -std=c++11 -c image_drawing.cpp

image_output.o: image_output.cpp image_menu.h Image.h
	g++ -std=c++11 -c

Image.o: Image.cpp image.cpp Image.h
	g++ -std=c++11 -c