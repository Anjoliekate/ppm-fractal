/*
#include <iostream>
#include "image_menu.h"
#include "PPM.h"


PPM::PPM( )
    :Image(), maxColorVal(1){} //The default constructor. A default PPM has max color value of 1, and a default constructed Image portion.

PPM::PPM( const int& height, const int& width ){
    maxColorVal = 1;
    Image(height, width);
} //The max color value should be set to 1. The Image portion should be initialized with the height and width parameters.

int PPM::getMaxColorValue( ) const{
    return maxColorVal;
} //Returns the maximum color value of the PPM.

bool PPM::valueValid( const int& value ) const{
    if( value < 0 || value > maxColorVal){
        return false;
    }
    return true;
} //Checks if value is a legal color value for this image. Legal means at least 0 and no more than the maximum color value. Returns true if it is legal, false otherwise.
void PPM::setMaxColorValue( const int& max_color_value ); //Change the maximum color value of the PPM. Only values 1 to 255, inclusive should be accepted. If the value is not accepted, make no changes.

void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ); //If value is valid (use the valueValid method), then call Image::setChannel() passing in the parameters. If value is not valid, do nothing.

void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ); //Set all three channels for the specified pixel. Should use setChannel to do the work.

void PPM::writeStream(std::ostream& os) const{
    os << "P6 " << width << " " << height << " " << maxColorVal << "\n";
    for (int row = 0; row < height; row++){
        for ( int column = 0; column < width; column++){
            unsigned int c = getChannel(row, column, 0);
            os.write((char * )&c, sizeof(c));
            unsigned int c = getChannel(row, column, 1);
            os.write((char * )&c, sizeof(c));
            unsigned int c = getChannel(row, column, 2);
            os.write((char * )&c, sizeof(c)); }
}
} //Writes the PPM data to the output stream os. Uses the format mentioned above. The first line of data is ASCII text, and the rest is binary data.
*/