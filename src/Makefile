all: hello questions_3 ascii_image image_file ActionData.o MenuData.o ppm_menu 


hello: hello.o 
	g++ -o hello hello.o

hello.o: hello.cpp
	g++ -c hello.cpp


questions_3: questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o ActionData.o MenuData.o image_filters.o
	g++ -o questions_3 questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o ActionData.o MenuData.o image_filters.o

questions_3.o: questions_3.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c questions_3.cpp

user_io.o: user_io.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c user_io.cpp

controllers.o: controllers.cpp user_io.o image_drawing.o image_output.o Image.o PPM.o MenuData.o ActionData.o image_filters.o ppm_menu.o 
	g++ -c controllers.cpp


ascii_image: ascii_image.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o ActionData.o MenuData.o image_filters.o
	g++ -o ascii_image ascii_image.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o ActionData.o MenuData.o image_filters.o

ascii_image.o: ascii_image.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c ascii_image.cpp

image_drawing.o: image_drawing.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c image_drawing.cpp

image_output.o: image_output.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c image_output.cpp

Image.o: Image.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c Image.cpp



image_file: image_file.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o MenuData.o ActionData.o image_filters.o 
	g++ -o image_file image_file.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o MenuData.o ActionData.o image_filters.o 

image_file.o: image_file.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c image_file.cpp 

PPM.o: PPM.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c PPM.cpp

flag_romania: flag_romania.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o
	g++ -o flag_romania flag_romania.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o

flag_romania.o: flag_romania.cpp image_menu.h Image.h PPM.h
	g++ -c flag_romania.cpp

buck: buck.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o
	g++ -o buck buck.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o
buck.o: buck.cpp image_menu.h Image.h PPM.h
	g++ -c buck.cpp


ActionData.o: ActionData.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c ActionData.cpp

MenuData.o: MenuData.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h 
	g++ -c MenuData.cpp


ppm_menu: ppm_menu.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o MenuData.o ActionData.o image_filters.o NumberGrid.o
	g++ -o ppm_menu ppm_menu.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o MenuData.o ActionData.o image_filters.o NumberGrid.o

ppm_menu.o: ppm_menu.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h NumberGrid.h
	g++ -c ppm_menu.cpp 


image_filters.o: image_filters.cpp image_menu.h Image.h PPM.h MenuData.h ActionData.h
	g++ -c image_filters.cpp

clean:
	-rm -f *.h.gch
	-rm -f *.ppm
	-rm -f *.o
	-rm -f hello questions_3 ascii_image image_file flag_romania ActionData MenuData ppm_menu
	