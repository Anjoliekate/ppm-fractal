#include <iostream>
#include <fstream>
#include "Image.h"
#include "image_menu.h"
#include "PPM.h"

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
                os << "@";
            }
            else if (color >= 0.9){
                os << "#";
            }
            else if(color >= 0.8){
                os << "%";
            }
            else if(color >= 0.7){
                os << "*";
            }
            else if (color >= 0.6){
                os <<"|";
            }
            else if(color >= 0.5){
                os << "+";
            }
            else if(color >= 0.4){
                os << ";";
            }
            else if(color >= 0.3){
                os << "~";
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
        os << std::endl;
    }
    (void) is;
}

    void writeUserImage(std::istream& is, std::ostream& os, const PPM& p){
        std::string name_of_file;
        name_of_file = getString(is, os, "Output filename? ");
        std::ofstream file(name_of_file, std::ios::binary);
        p.writeStream(file);
        file.close();
       
    }
    