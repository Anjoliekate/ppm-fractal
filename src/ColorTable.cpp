#include "ColorTable.h"
#include <vector>
#include <random>
#include <iostream>

Color::Color( )
: intRed(0), intGreen(0), intBlue(0){};
// Sets all color channels to value 0.

Color::Color( const int& red, const int& green, const int& blue )
: intRed(red), intGreen(green), intBlue(blue){}

// Sets the color channels to the values provided here. No range checking is applied.

int Color::getRed( ) const {
    return intRed;
}
// Returns the value of the red channel.

int Color::getGreen( ) const{
    return intGreen;
}
// Returns the value of the green channel.

int Color::getBlue( ) const{
    return intBlue;
}
// Returns the value of the blue channel.

int Color::getChannel( const int& channel ) const{ //come back to 
    if (channel == 0){
        return intRed;
    }
    else if (channel == 1){
        return intGreen;
    }
    else if (channel == 2){
        return intBlue;
    }
    return -1;
    
}
// Returns the value of the channelth channel. 0 == red, 1 == green, 2 == blue. Returns -1 if the channel is out of range.

void Color::setRed( const int& value ){
    if (value >= 0){
    intRed = value;
    }
}
// Changes the red channel to value. If value is less than 0, do not make any changes.

void Color::setGreen( const int& value ){
    if (value >= 0){
    intGreen = value;
    }    
} //Changes the green channel to value. If value is less than 0, do not make any changes.

void Color::setBlue( const int& value ){
    if (value >= 0){
    intBlue = value;
    }
} //Changes the blue channel to value. If value is less than 0, do not make any changes.

void Color::setChannel( const int& channel, const int& value ){
    if (channel == 0){
        setRed(value);
    }
    else if (channel == 1){
        setGreen(value);
    }
    else if (channel == 2){
        setBlue(value);
    }
} //Changes the channelth channel to value. If value is less than 0, do not make any changes. 0 == red, 1 == green, 2 == blue. Does not make changes if channel is out of range.

void Color::invert( const int& max_color_value ){
//subtract each channel from max color value if less
    if (getRed() <= max_color_value && getGreen() <= max_color_value && getBlue() <= max_color_value){
        int invertRed = (max_color_value - getRed());
        setChannel(0, invertRed);
        int invertGreen = (max_color_value - getGreen());
        setChannel(1, invertGreen);
        int invertBlue = (max_color_value - getBlue());
        setChannel(2, invertBlue);
    }

} //Inverts the red, green and blue channels, using max_color_value. If max_color_value is
// less than any of the current color channels (red, green or blue), then make no changes.
// The inversion is completed by subtracting the current value from max_color_value. For example:
// red = max_color_value - red. This only makes sense if red is <= max_color_value. That’s why we make no changes if any channel (red, green or blue) is larger than max_color_value.

bool Color::operator==( const Color& rhs ) const{
    return this->getChannel(0) == rhs.getChannel(0) && this->getChannel(1) == rhs.getChannel(1) && this->getChannel(2) == rhs.getChannel(2) ;
} //Returns true if *this and rhs have the same color values. Otherwise, returns false.

std::ostream& operator<<( std::ostream& os, const Color& color ){
    int red = color.getRed();
    int green = color.getGreen();
    int blue = color.getBlue();
    os << red << ":" << green << ":" << blue; 
    return os;
} 
//Displays the color to os in the following format: “red:green:blue”. For example, if the color has red = 13, green = 2 and blue = 45, then the output would be “13:2:45”.

ColorTable::ColorTable( const int& num_color )
:colorCollection(num_color) {}
// Sizes the Color collection to num_color items.

int ColorTable::getNumberOfColors( ) const {
    return colorCollection.size();
}// Returns the number of Colors stored.

void ColorTable::setNumberOfColors( const int& num_color ){
    colorCollection.resize(num_color);
} //Resizes the collection to hold num_color items. Previous Color contents may or may not be preserved.

const Color& ColorTable::operator[]( const int& i ) const{
    if (i >= getNumberOfColors() || i < 0) {
    static Color ec( -1, -1, -1 );
    static Color c( -1, -1, -1 );
    c = ec;
    return c;
    }
    else{
    return colorCollection[i];
    }
}
//Returns the ith Color in the collection. If i is out of range, returns a static memory Color object with all three channels set to -1. See an example below.

Color& ColorTable::operator[]( const int& i ){
    if (i >= getNumberOfColors() || i < 0) {
    static Color ec( -1, -1, -1 );
    static Color c( -1, -1, -1 );
    c = ec;
    return c;
    }
    else{
    return colorCollection[i];
    }
}
// Returns the ith Color in the collection. If i is out of range, returns a static memory Color object with all three channels set to -1.

void ColorTable::setRandomColor( const int& max_color_value, const int& position ){
    if (position >= 0 && position < getNumberOfColors() && max_color_value >= 0) {
        int red = (std::rand() % (max_color_value + 1));
        int green = (std::rand() % (max_color_value + 1));
        int blue = (std::rand() % (max_color_value + 1));
        Color& color = colorCollection[position];
        color.setRed(red);
        color.setGreen(green);
        color.setBlue(blue);
        
    }
}

// Assigns the positionth color random values for all three channels. The random values are
// between 0 and max_color_value, inclusive. If position is out of range, no change is made. 
//If max_color_value is less than 0, no change is made. This method should NOT use std::srand() Add std::srand(std::time(0)); to main() of ppm_menu.cpp.

double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const{
    return (y2 - y1)/(x2 - x1);
    
}
// Calculates a slope from point 1 to point 2, using “rise-over-run” calculation. Be sure to use floating point division operation.

double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const{
    return y1 + (x - x1) * slope;
}
// Calculate the y-value along the gradient from point (x1,y1) to the point at position x.

void ColorTable::insertGradient( const Color& color1, const Color& color2, const int& position1, const int& position2 ){
if (position1 < position2 && position1 < getNumberOfColors() && position2 < getNumberOfColors() && position1 >= 0 && position2 >= 0){
    for (int i = position1; i <= position2; ++i){
        for (int channel = 0; channel < 3; ++channel){
            int color1Channel = color1.getChannel(channel);
            int color2Channel = color2.getChannel(channel);
            double slope = gradientSlope(color1Channel, color2Channel, position1, position2);
            double gradientVal = gradientValue(color1Channel, position1, slope, i);
            colorCollection[i].setChannel(channel, gradientVal);

        }
    }
}

} //Change the colors from position1 to position2, inclusive, to be gradients from color1 to color2. 
//If position1 is not less than position2, no change is made. If either position is out of range, 
//no change is made. Should use the gradientSlope() and gradientValue() methods.

int ColorTable::getMaxChannelValue( ) const{
    int maxVal = 0;
    for(int i = 0; i < getNumberOfColors(); i++){
    for (int channel = 0; channel < 3; channel++){
        int temporary = maxVal;
        if(colorCollection[i].getChannel(channel) > maxVal){
            maxVal = colorCollection[i].getChannel(channel);
        }
        else{
            maxVal = temporary;
        }
    }
    }
    return maxVal;

} //Finds the largest value of any red, greeen, or blue value in any color in the table.


