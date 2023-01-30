flags = -std=c++11

all: hello questions_3 ascii_image


hello: hello.o 
	g++ $(flags) -o hello hello.o

hello.o: hello.cpp
	g++ $(flags) -c hello.cpp


questions_3: questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o
	g++ $(flags) -o questions_3 questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o

questions_3.o: questions_3.cpp image_menu.h Image.h
	g++ $(flags) -c questions_3.cpp

user_io.o: user_io.cpp image_menu.h Image.h
	g++ $(flags) -c user_io.cpp

controllers.o: controllers.cpp image_menu.h Image.h
	g++ $(flags) -c controllers.cpp



ascii_image: ascii_image.o Image.o controllers.o image_drawing.o image_output.o user_io.o 
	g++ $(flags) -o ascii_image ascii_image.o Image.o controllers.o image_drawing.o image_output.o user_io.o

ascii_image.o: ascii_image.cpp image_menu.h Image.h
	g++ $(flags) -c ascii_image.cpp

image_drawing.o: image_drawing.cpp image_menu.h Image.h
	g++ $(flags) -c image_drawing.cpp

image_output.o: image_output.cpp image_menu.h Image.h
	g++ $(flags) -c image_output.cpp

Image.o: Image.cpp image_menu.h Image.h
	g++ $(flags) -c Image.cpp

clean:
	-rm -f *.o
	-rm -f hello questions_3 ascii_image