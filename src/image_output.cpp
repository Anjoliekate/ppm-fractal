#include <iostream>
#include "Image.h"
#inlcude "image_menu.h"

void drawAsciiImage( std::istream& is, std::ostream& os, const Image& image ){
    int height = image.getHeight();
    int width = image.getWidth();
    for(int row = 0; row < height; row++){
        for(int column = 0; column < width; column++){

            int r = image.getChannel(row, column, 0);
            int g = image.getChannel(row, column, 1);
            int b = image.getChannel(row, column, 2);
            double color = (r + g + b)/765.0;
            if (color >= 1.0){
                std::cout << "@";
            }
            else if (color >= 0.9){
                std::cout << "#";
            }
            else if(color >= 0.8){
                std::cout << "%";
            }
            else if(color >= 0.7){
                std::cout << "*";
            }
            else if (color >= 0.6){
                std::cout <<"|";
            }
            else if(color >= 0.5){
                std::cout << "+";
            }
            else if(color >= 0.4){
                std::cout << ";";
            }
            else if(color >= 0.3){
                std::cout << "~";
            }
            else if(color >= 0.2){
                os << "-";
            }
            else if(color >= 0.1){
                os << ".";
            }
            else if(color >= 0.0){
                os << " ";
            }
        }
    }
}