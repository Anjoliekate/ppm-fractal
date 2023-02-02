#include <iostream>
#include "image_menu.h"
#include "PPM.h"

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

    void stripedDiagonalPattern(std::istream& is, std::ostream& os, PPM& p){
        int height = getInteger(is, os, "Image height? ");
        int width = getInteger(is, os, "Image width? ");
        p.setHeight(height);
        p.setWidth(width);
        int calcMaxVal = (width + height)/3;
        if (calcMaxVal > 255){
            calcMaxVal = 255;
        }
        p.setMaxColorValue(calcMaxVal);  
        for(int row = 0; row < p.getHeight(); row++){
            for(int column = 0; column < p.getWidth(); column++){
                if(row < height / 2){
                    p.setChannel(row, column, 0, 0);
                }
                else if(row >= height / 2  && (row % 3) == 0){
                    p.setChannel(row, column, 0, 0);
                }
                else if (row >= height / 2  && (row % 3) != 0){
                    p.setChannel(row, column, 0, p.getMaxColorValue());
                }
                p.setChannel(row, column, 1, (row + p.getWidth() - column - 1) % (p.getMaxColorValue() + 1));

                if(column < row){
                    p.setChannel(row, column, 2, 0);
                }
                else{
                    p.setChannel(row, column, 2, p.getMaxColorValue());
                }
        }
    }
}