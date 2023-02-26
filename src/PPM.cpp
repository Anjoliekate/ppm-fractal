#include <iostream>
#include "image_menu.h"
#include "PPM.h"

PPM::PPM()
    : Image(), maxColorVal(1){}
    //The default constructor. A default PPM has max color value of 1, and a default constructed Image portion.

PPM::PPM( const int& height_input, const int& width_input )
    : Image(height_input, width_input), maxColorVal(1) {}  //The max color value should be set to 1. The Image portion should be initialized with the height and width parameters.

int PPM::getMaxColorValue() const{
    return maxColorVal;
} //Returns the maximum color value of the PPM.

bool PPM::valueValid( const int& value ) const{
    return (value >= 0 && value <= maxColorVal);
} //Checks if value is a legal color value for this image. Legal means at least 0 and no more than the maximum color value. Returns true if it is legal, false otherwise.

void PPM::setMaxColorValue( const int& max_color_value ){
    if (max_color_value <= 255 && max_color_value >= 1 ){
        maxColorVal = max_color_value;
    }
} //Change the maximum color value of the PPM. Only values 1 to 255, inclusive should be accepted. If the value is not accepted, make no changes.

void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ){
    if (valueValid(value)){
        Image::setChannel(row, column, channel, value);
    }
} //If value is valid (use the valueValid method), then call Image::setChannel() passing in the parameters. If value is not valid, do nothing.

void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ){
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
} //Set all three channels for the specified pixel. Should use setChannel to do the work.

void PPM::writeStream(std::ostream& os) const{
    os << "P6 " << getWidth() << " " << getHeight() << " " << getMaxColorValue() << "\n";
    for (int row = 0; row < getHeight(); row++){
        for ( int column = 0; column < getWidth(); column++){
            unsigned int byte = getChannel(row, column, 0);
            os.write((char * )&byte, 1);
            unsigned int byte1 = getChannel(row, column, 1);
            os.write((char * )&byte1, 1);
            unsigned int byte2 = getChannel(row, column, 2);
            os.write((char * )&byte2, 1); 
            }
        }
} //Writes the PPM data to the output stream os. Uses the format mentioned above. The first line of data is ASCII text, and the rest is binary data.

void PPM::readStream(std::istream& is){
    std::string P6;
    is >> P6;
    int width;
    is >> width;
    setWidth(width);
    int height;
    is >> height;
    setHeight(height);
    int maxColorValue;
    is >> maxColorValue;
    setMaxColorValue(maxColorValue);
    unsigned char byte;
    is.read((char *)&byte, 1);
    for (int row = 0; row < height; row ++){
        for (int column = 0; column < width; column++){
            for(int channel = 0; channel < 3; channel++){
                is.read((char *)&byte, 1);
                setChannel(row, column, channel, byte);
            }
        }
    }

}
//multiply *this and rhs then test each condition and return it

bool PPM::operator==( const PPM& rhs ) const{ 
    return (getHeight() * getWidth() == rhs.getHeight()* getWidth());
} 
bool PPM::operator!=( const PPM& rhs ) const{
    return (getHeight() * getWidth() != rhs.getHeight()* getWidth());
  
}
bool PPM::operator<( const PPM& rhs ) const{
    return (getHeight() * getWidth() < rhs.getHeight()* getWidth());
  
}
bool PPM::operator>( const PPM& rhs ) const{
    return (getHeight() * getWidth() > rhs.getHeight()* getWidth());
  
}
bool PPM::operator<=( const PPM& rhs ) const{
    return (getHeight() * getWidth() <= rhs.getHeight()* getWidth());
  
}
bool PPM::operator>=( const PPM& rhs ) const{
    return (getHeight() * getWidth() >= rhs.getHeight()* getWidth());
}

PPM& PPM::operator+=( const PPM& rhs ){//use ternary for cleaner code and ease of use
    int maxCV = getMaxColorValue();
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) + rhs.getChannel(row, column, 0));
            redChannel = redChannel > maxCV ? maxCV : redChannel;
            int greenChannel = (getChannel(row, column, 1) + rhs.getChannel(row, column, 1));
            greenChannel = greenChannel > maxCV ? maxCV : greenChannel;
            int blueChannel = (getChannel(row, column, 2) + rhs.getChannel(row, column, 2));
            blueChannel = blueChannel > maxCV ? maxCV : blueChannel;              
            setChannel(row, column, 0, redChannel);
            setChannel(row, column, 1, greenChannel);
            setChannel(row, column, 2, blueChannel);
        }
    }
    return *this;
} // Assumes *this and rhs have the same width and height. Adds the channel values from rhs into the channels 
//for *this. If the resulting value is larger than max color value, set to max color value. Returns *this.

PPM& PPM::operator-=( const PPM& rhs ){
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) - rhs.getChannel(row, column, 0));
            redChannel = redChannel < 0 ? 0 : redChannel;
            int greenChannel = (getChannel(row, column, 1) - rhs.getChannel(row, column, 1));
            greenChannel = greenChannel < 0 ? 0 : greenChannel;
            int blueChannel = (getChannel(row, column, 2) - rhs.getChannel(row, column, 2));
            blueChannel = blueChannel < 0 ? 0 : blueChannel;
            setChannel(row, column, 0, redChannel);
            setChannel(row, column, 1, greenChannel);
            setChannel(row, column, 2, blueChannel);
        }
    }
    return *this;
} 
//Assumes *this and rhs have the same width and height. Subtracts the channel values from rhs
// from the channels for *this. If the resulting value is less than 0, set to 0. Returns *this.

PPM& PPM::operator*=( const double& rhs ){ //comeback to this one
    int maxCV = getMaxColorValue();
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) * rhs);
            redChannel = redChannel > maxCV ? maxCV : redChannel;
            redChannel = redChannel < 0 ? 0 : redChannel;
            int greenChannel = (getChannel(row, column, 1) * rhs);
            greenChannel = greenChannel > maxCV ? maxCV : greenChannel;
            greenChannel = greenChannel < 0 ? 0 : greenChannel;
            int blueChannel = (getChannel(row, column, 2) * rhs);
            blueChannel = blueChannel > maxCV ? maxCV : blueChannel;
            blueChannel = blueChannel < 0 ? 0 : blueChannel;
            setChannel(row, column, 0, redChannel);
            setChannel(row, column, 1, greenChannel);
            setChannel(row, column, 2, blueChannel);
        }
    }
    return *this;
} 
// Multiples every channel value of *this by rhs. If the resulting value
// is larger than max color value, set to max color value. If the resulting
// value is less than 0, set to 0. Returns *this.


PPM& PPM::operator/=( const double& rhs ){
    int maxCV = getMaxColorValue();
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) / rhs);
            redChannel = redChannel > maxCV ? maxCV : redChannel;
            redChannel = redChannel < 0 ? 0 : redChannel;
            int greenChannel = (getChannel(row, column, 1) / rhs);
            greenChannel = greenChannel > maxCV ? maxCV : greenChannel;
            greenChannel = greenChannel < 0 ? 0 : greenChannel;
            int blueChannel = (getChannel(row, column, 2) / rhs);
            blueChannel = blueChannel > maxCV ? maxCV : blueChannel;
            blueChannel = blueChannel < 0 ? 0 : blueChannel;
            setChannel(row, column, 0, redChannel);
            setChannel(row, column, 1, greenChannel);
            setChannel(row, column, 2, blueChannel);
        }
    }
    return *this;
} 
//Divides every channel value of *this by rhs. If the resulting value is larger 
//than max color value, set to max color value. If the resulting value is less than 0, set to 0. Returns *this.

PPM PPM::operator+( const PPM& rhs ) const{
    PPM ppm(getHeight(), getWidth());
    int maxCV = getMaxColorValue();
    ppm.setMaxColorValue(maxCV);
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) + rhs.getChannel(row, column, 0));
            redChannel = redChannel > maxCV ? maxCV : redChannel;
            int greenChannel = (getChannel(row, column, 1) + rhs.getChannel(row, column, 1));
            greenChannel = greenChannel > maxCV ? maxCV : greenChannel;
            int blueChannel = (getChannel(row, column, 2) + rhs.getChannel(row, column, 2));
            blueChannel = blueChannel > maxCV ? maxCV : blueChannel;
            ppm.setChannel(row, column, 0, redChannel);
            ppm.setChannel(row, column, 1, greenChannel);
            ppm.setChannel(row, column, 2, blueChannel);
        }
    }
    return ppm;
} 
//Creates a new PPM object with the same meta data (height, width, max color value) as *this. 
//Sets the channel values in the new object to the sum of the channel values for *this and rhs. 
//If the value is greater than max color value, set to max color value. Returns the new object.

PPM PPM::operator-( const PPM& rhs ) const{
    PPM ppm(getHeight(), getWidth());
    int maxCV = getMaxColorValue();
    ppm.setMaxColorValue(maxCV);
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) - rhs.getChannel(row, column, 0));
            redChannel = redChannel < 0 ? 0 : redChannel;
            int greenChannel = (getChannel(row, column, 1) - rhs.getChannel(row, column, 1));
            greenChannel = greenChannel < 0 ? 0 : greenChannel;
            int blueChannel = (getChannel(row, column, 2) - rhs.getChannel(row, column, 2));
            blueChannel = blueChannel < 0 ? 0 : blueChannel;
            ppm.setChannel(row, column, 0, redChannel);
            ppm.setChannel(row, column, 1, greenChannel);
            ppm.setChannel(row, column, 2, blueChannel);
        }
    }
    return ppm;
} //Creates a new PPM object with the same meta data (height, width, max color value) 
//as *this. Sets the channel values in the new object to the difference of the channel values for *this and rhs. 
//If the value is less than 0, set to 0. Returns the new object.

PPM PPM::operator*( const double& rhs ) const{
    PPM ppm(getHeight(), getWidth());
    int maxCV = getMaxColorValue();
    ppm.setMaxColorValue(maxCV);
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) * rhs);
            redChannel = redChannel > maxCV ? maxCV : redChannel;
            redChannel = redChannel < 0 ? 0 : redChannel;
            int greenChannel = (getChannel(row, column, 1) * rhs);
            greenChannel = greenChannel > maxCV ? maxCV : greenChannel;
            greenChannel = greenChannel < 0 ? 0 : greenChannel;
            int blueChannel = (getChannel(row, column, 2) * rhs);
            blueChannel = blueChannel > maxCV ? maxCV : blueChannel;
            blueChannel = blueChannel < 0 ? 0 : blueChannel;
            ppm.setChannel(row, column, 0, redChannel);
            ppm.setChannel(row, column, 1, greenChannel);
            ppm.setChannel(row, column, 2, blueChannel);
        }
    }
    return ppm;
}//Creates a new PPM object with the same meta data (height, width, max color value)
// as *this. Sets the channel values in the new object to the product of the channel 
//values for *this and the value of rhs. If the value is greater than max color value, set to max color value.
// If the value is less than 0, set to 0. Returns the new object.

PPM PPM::operator/( const double& rhs ) const{
    PPM ppm(getHeight(), getWidth());
    int maxCV = getMaxColorValue();
    ppm.setMaxColorValue(maxCV);
    for (int row = 0; row < getHeight(); row++){
        for(int column = 0; column < getWidth(); column++){
            int redChannel = (getChannel(row, column, 0) / rhs);
            redChannel = redChannel > maxCV ? maxCV : redChannel;
            redChannel = redChannel < 0 ? 0 : redChannel;
            int greenChannel = (getChannel(row, column, 1) / rhs);
            greenChannel = greenChannel > maxCV ? maxCV : greenChannel;
            greenChannel = greenChannel < 0 ? 0 : greenChannel;
            int blueChannel = (getChannel(row, column, 2) / rhs);
            blueChannel = blueChannel > maxCV ? maxCV : blueChannel;
            blueChannel = blueChannel < 0 ? 0 : blueChannel;
            ppm.setChannel(row, column, 0, redChannel);
            ppm.setChannel(row, column, 1, greenChannel);
            ppm.setChannel(row, column, 2, blueChannel);
        }
    }
    return ppm;
} 
//Creates a new PPM object with the same meta data (height, width, max color value)
// as *this. Sets the channel values in the new object to the division of the channel
// values of *this and by the value of rhs. If the value is greater than max color value, 
//set to max color value. If the value is less than 0, set to 0. Returns the new object.


