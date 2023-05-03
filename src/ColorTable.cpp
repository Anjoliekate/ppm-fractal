#include "ColorTable.h"
#include <vector>
#include <random>
#include <iostream>
#include <cmath>
#include <list>
#include <cstdlib>


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

void Color::setFromHSV(const double& hue, const double& saturation, const double& value){
    double(intRed);
    double(intGreen);
    double(intBlue);
    HSV_to_RGB(hue, saturation, value, intRed, intGreen, intBlue);
} //Sets the color’s data members for RGB values by converting the inputs using the HSV_to_RGB() function.
void Color::getHSV(double& hue, double& saturation, double& value) const{
    RGB_to_HSV(double(intRed), double(intGreen), double(intBlue), hue, saturation, value);
} //Sets the non-const reference parameters to the HSV values obtained by converting the color’s data member RGB values with the RGB_to_HSV() function.


void HSV_to_RGB(const double& hue, const double& saturation, const double& value, double& red, double &green, double& blue) {
  /* Convert Hue, Saturation, Value to Red, Green, Blue
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
   *
   * Inputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   *
   * Outputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   */
  if(hue < 0.0 || hue > 360.0 || saturation < 0.0 || saturation > 1.0 || value < 0.0 || value > 1.0) {
    red = green = blue = 0.0;
    std::cerr << "HSV_to_RGB() input parameters out of range." << std::endl
              << " hue: " << hue  << std::endl
              << " saturation: " << saturation << std::endl
              << " value: " << value << std::endl;
    return;
  }

  // chroma selects the strength of the "primary" color of the current area of the wheel
  double chroma = value * saturation;
  // hue2 selects which 60-degree wedge of the color wheel we are in
  double hue2 = hue / 60.0;
  // x selects the strength of the "secondary" color of the current area of the wheel
  double x = chroma * ( 1 - std::abs( std::fmod( hue2, 2 ) - 1 ) );
  if( hue2 >= 0 && hue2 < 1 ) {
    red = chroma;
    green = x;
    blue = 0.0;
  } else if( hue2 >= 1 && hue2 < 2 ) {
    red = x;
    green = chroma;
    blue = 0.0;
  } else if( hue2 >= 2 && hue2 < 3 ) {
    red = 0.0;
    green = chroma;
    blue = x;
  } else if( hue2 >= 3 && hue2 < 4 ) {
    red = 0.0;
    green = x;
    blue = chroma;
  } else if( hue2 >= 4 && hue2 < 5 ) {
    red = x;
    green = 0.0;
    blue = chroma;
  } else if( hue2 >= 5 && hue2 <= 6 ) {
    red = chroma;
    green = 0.0;
    blue = x;
  } else {
    red = 0;
    green = 0;
    blue = 0;
  }

  // m scales all color channels to obtain the overall brightness.
  double m = value - chroma;
  red = 255.0*( red + m );
  green = 255.0*( green + m );
  blue = 255.0*( blue + m );
}

void RGB_to_HSV(const double& red0, const double &green0, const double& blue0, double& hue, double& saturation, double& value) {
  /* Red, Green, Blue to Convert Hue, Saturation, Value
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
   *
   * Inputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   *
   * Outputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   */
  if(red0 < 0.0 || red0 > 255.0 || green0 < 0.0 || green0 > 255.0 || blue0 < 0.0 || blue0 > 255.0) {
    hue = saturation = value = 0.0;
    std::cerr << "RGB_to_HSV() input parameters out of range." << std::endl
              << " red: " << red0  << std::endl
              << " green: " << green0 << std::endl
              << " blue: " << blue0 << std::endl;
    return;
  }

  double red   = red0 / 255.0;
  double green = green0 / 255.0;
  double blue  = blue0 / 255.0;

  // x_max helps identify the primary hue
  double x_max = red;
  if(green > x_max) { x_max = green; }
  if(blue > x_max) { x_max = blue; }
  value = x_max;

  double x_min = red;
  if(green < x_min) { x_min = green; }
  if(blue < x_min) { x_min = blue; }

  double chroma = x_max - x_min;

  if(chroma == 0) {
    hue = 0;
  } else if(value == red) {
    hue = 60.0 * (0 + (green - blue)/chroma);
  } else if(value == green) {
    hue = 60.0 * (2 + (blue - red)/chroma);
  } else if(value == blue) {
    hue = 60.0 * (4 + (red - green)/chroma);
  } else {
    hue = -720.0;
  }
  if(hue < 0.0) {
    hue += 360.0;
  }

  if(value == 0.0) {
    saturation = 0.0;
  } else {
    saturation = chroma/value;
  }

}

void ColorTable::insertHueSaturationValueGradient(const Color& color1, const Color& color2, const int& position1, const int& position2){
    //make sure the positions are valid
    std::vector<double>list1;
    std::vector<double>list2;

    if (position1 < position2 && position1 < getNumberOfColors() && position2 < getNumberOfColors() && position1 >= 0 && position2 >= 0){
        double hue1;
        double value1;
        double saturation1;
        double hue2;
        double value2;
        double saturation2;

        int red1 = color1.getRed();
        int blue1 = color1.getBlue();
        int green1 = color1.getGreen();
        int red2 = color2.getRed();
        int green2 = color2.getGreen();
        int blue2 = color2.getBlue();
        RGB_to_HSV(red1, green1, blue1, hue1, saturation1, value1 );
        RGB_to_HSV(red2, green2, blue2, hue2, saturation2, value2 );

        color1.getHSV(hue1, saturation1, value1);
        color2.getHSV(hue2, saturation2, value2);

        double hueslope = gradientSlope(0, 360, position1, position2);
        double saturationSlope = gradientSlope(0, 1, position1, position2);
        double valueSlope = gradientSlope(0, 1, position1, position2);

    //get the HSV values from both colors (previous exam task has these conversions)
    //calculate the hue slope, the saturation slope, and the value slope

    for (int i = position1; i <= position2; ++i){
        for (int channel = 0; channel < 3; ++channel){
            double hueVal1 = gradientValue(hue1, position1, hueslope, i);
            double satVal1 = gradientValue(saturation1, position1, saturationSlope, i);
            double valVal1 = gradientValue(value1, position1, valueSlope, i);
            double hueVal2 = gradientValue(hue2, position1, hueslope, i);
            double satVal2 = gradientValue(saturation2, position1, saturationSlope, i);
            double valVal2 = gradientValue(value2, position1, valueSlope, i);
            colorCollection[i].setFromHSV(hueVal1, satVal1, valVal1);
            colorCollection[i].setFromHSV(hueVal2, satVal2, valVal2);
        //not sure on this one I'm sure it is structured similar to the correct way
        //I started to write your RGB to HSV without realizing which 
        //didn't leave me with enough time to debug.
        }
    }
}
    //for each position in the gradient
        //calculate the hue, the saturation, and the value.
        //set a color using the HSV (previous exam task has these conversions)
        //assign the color into the correct position in the color table.
}