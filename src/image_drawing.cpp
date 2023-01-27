#include <iostream>
#include "Image.h"
#include "image_menu.h"

void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image ){
    int height = getInteger(std::cin, std::cout, "Image height? ");
    int width = getInteger(std::cin, std::cout, "Image width? ");
    image.setHeight(height);
    image.setWidth(width);
    for(int row = 0; row < height; row++){
        for(int column = 0; column < width; column++){
            if(row < height / 2){
                image.setChannel(row, column, 0, 0);
            }
            else if(row >= height / 2){
                image.setChannel(row, column, 0, 255);
            }
            if (column < width / 2){
                image.setChannel(row, column, 2, 0);

            }
            else if(column >= width / 2){
                image.setChannel(row, column, 2, 255);
            }
            image.setChannel(row, column, 1, (2* row +2 * column)%256);

        }
    }
    
}