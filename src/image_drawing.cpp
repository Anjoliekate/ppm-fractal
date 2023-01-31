#include <iostream>
#include "image_menu.h"

void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image ){
    int height = getInteger(is, os, "Image height? ");
    int width = getInteger(is, os, "Image width? ");
    image.setHeight(height);
    image.setWidth(width);
    for(int row = 0; row < height; row++){
        for(int column = 0; column < width; column++){
            //set red channel
            if(row < height / 2){
                image.setChannel(row, column, 0, 0);
            }
            else if(row >= height / 2){
                image.setChannel(row, column, 0, 255);
            }
            //set blue channel
            if (column < width / 2){
                image.setChannel(row, column, 2, 0);

            }
            else if(column >= width / 2){
                image.setChannel(row, column, 2, 255);
            }
            //set green channel
            image.setChannel(row, column, 1, (2* row +2 * column)%256);
        }
    }
    (void) is;
    (void) os;
}
/*
    void stripedDiagonalPattern(std::istream& is, std::ostream& os, PPM& p){
        getInteger();
        
    };
*/