#include "image_menu.h"
#include "Image.h"
#include "PPM.h"
#include <iostream>

int assignment1( std::istream& is, std::ostream& os){
    return askQuestions3(is, os);
}
int assignment2( std::istream& is, std::ostream& os){
    Image image;
    diagonalQuadPattern(is, os, image);
    drawAsciiImage(is, os, image);
    return 0;
}

int assignment3(std::istream& is, std::ostream& os){
    PPM p;
    stripedDiagonalPattern(is, os, p);
    writeUserImage(is, os, p);
    return 0;
}
int flag_romania( std::istream& is, std::ostream& os ){
    PPM p;
    flagRomaniaPattern(is, os, p);
    writeUserImage(is, os, p);
    return 0;
}

int buck( std::istream& is, std::ostream& os ){
    return askUncleBuckQuestions(is, os);
}