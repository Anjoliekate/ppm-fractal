#include <iostream>
#include <vector>
#include "Image.h"
#include "image_menu.h"

    Image::Image(){
        int height = 0; 
        int width = 0;
        std::vector<int> imageVector(height * width*3);
    }

    Image::Image(const int& height_input, const int& width_input) {
        int height = height_input;
        int width = width_input;
        std::vector<int> imageVector(height * width*3);
    }
    
    int Image::getHeight() const {
        return height;
        }
    
    int Image::getWidth() const {
        return width;
        }
    
    bool Image::indexValid( const int& row, const int& column, const int& channel ) const{
    if (row >= getHeight() || row < 0 || column >= getWidth() || column < 0 || channel > 2 || channel < 0 ){
        return false;
    }
    return true;
    };

    int Image::index( const int& row, const int& column, const int& channel ) const 
    {
        return (row* width * 3) + (column *3) + channel;
    } 
    int Image::getChannel(const int& row, const int& column, const int& channel){
        if (indexValid(row, column, channel)){
            return imageVector[index(row, column, channel)];
        }
        else{
            return -1;
        }
    }
    void Image::setHeight( const int& height_input ) {
        if (height_input >= 0){
            height = height_input;
            imageVector.resize(height * width * 3);
        }
    }

    void Image::setWidth( const int& width_input ){
        if (width_input >= 0){
            width = width_input;
            imageVector.resize(height * width * 3);
        }
    }

    void Image::setChannel(const int& row, const int& column, const int& channel, const int& value ){
        if (indexValid(row, column, channel)){
            imageVector[index(row, column, channel)] = value;
        }
    }