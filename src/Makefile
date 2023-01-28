all:hello questions_3 ascii_image

hello: hello.o 
	g++ -o hello hello.o

hello.o: hello.cpp
	g++ -c hello.cpp



questions_3: questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o
	g++  -o questions_3 questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o

questions_3.o: questions_3.cpp image_menu.h
	g++ -c questions_3.cpp

controllers.o: controllers.cpp image_menu.h Image.h
	g++  -c controllers.cpp



ascii_image: ascii_image.o Image.o controllers.o image_drawing.o image_output.o user_io.o 
	g++  -o ascii_image ascii_image.o Image.o controllers.o image_drawing.o image_output.o user_io.o

ascii_image.o: ascii_image.cpp image_menu.h Image.h
	g++  -c ascii_image.cpp

image_drawing.o: image_drawing.cpp image_menu.h Image.h
	g++  -c image_drawing.cpp

image_output.o: image_output.cpp image_menu.h Image.h
	g++  -c

Image.o: Image.cpp image_menu.h Image.h
	g++  -c

clean:
	-rm -f *.o
	-rm -f hello questions_3
	-rm -f hello questions_3 ascii_image