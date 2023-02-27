#include <iostream>
#include "image_menu.h"
#include "PPM.h"
#include "ActionData.h"
#include <cmath>

void diagonalQuadPattern( ActionData& action_data  ){
    int height = getInteger(action_data, "Image height? ");
    int width = getInteger(action_data, "Image width? ");
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    action_data.getInputImage1().setMaxColorValue(255);
    
    for(int row = 0; row < height; row++){
        for(int column = 0; column < width; column++){
            //set red channel
            if(row < height / 2){
                action_data.getInputImage1().setChannel(row, column, 0, 0);
            }
            else if(row >= height / 2){
                action_data.getInputImage1().setChannel(row, column, 0, 255);
            }
            //set blue channel
            if (column < width / 2){
                action_data.getInputImage1().setChannel(row, column, 2, 0);

            }
            else if(column >= width / 2){
                action_data.getInputImage1().setChannel(row, column, 2, 255);
            }
            //set green channel
            action_data.getInputImage1().setChannel(row, column, 1, (2* row +2 * column)%256);
        }
    }
}

    void stripedDiagonalPattern(ActionData& action_data ){
        int height = getInteger(action_data, "Image height? ");
        int width = getInteger(action_data, "Image width? ");
        action_data.getInputImage1().setHeight(height);
        action_data.getInputImage1().setWidth(width);
        int calcMaxVal = (width + height)/3;
        if (calcMaxVal > 255){
            calcMaxVal = 255;
        }
        action_data.getInputImage1().setMaxColorValue(calcMaxVal);  
        for(int row = 0; row < action_data.getInputImage1().getHeight(); row++){
            for(int column = 0; column < action_data.getInputImage1().getWidth(); column++){
                if(row < height / 2){
                    action_data.getInputImage1().setChannel(row, column, 0, 0);
                }
                else if(row >= height / 2  && (row % 3) == 0){
                    action_data.getInputImage1().setChannel(row, column, 0, 0);
                }
                else if (row >= height / 2  && (row % 3) != 0){
                    action_data.getInputImage1().setChannel(row, column, 0, action_data.getInputImage1().getMaxColorValue());
                }
                action_data.getInputImage1().setChannel(row, column, 1, (row + action_data.getInputImage1().getWidth() - column - 1) % (action_data.getInputImage1().getMaxColorValue() + 1));

                if(column < row){
                    action_data.getInputImage1().setChannel(row, column, 2, 0);
                }
                else{
                    action_data.getInputImage1().setChannel(row, column, 2, action_data.getInputImage1().getMaxColorValue());
                }
        }
    }
}

void flagRomaniaPattern( ActionData& action_data ){
    int height = getInteger(action_data, "Image height? ");
    action_data.getInputImage1().setHeight(height);
    int width = (height * 3);
    action_data.getInputImage1().setWidth(width);
    action_data.getInputImage1().setMaxColorValue(255);
    int formula = height / 3;
    int middle = formula * 2;
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++){
        for (int column = 0; column < action_data.getInputImage1().getWidth(); column++){
            if (column < formula){
                action_data.getInputImage1().setChannel(row, column, 0, 0);
                action_data.getInputImage1().setChannel(row, column, 1, 43);
                action_data.getInputImage1().setChannel(row, column, 2, 127);
            }
            else if (column > formula && column <= middle){
                action_data.getInputImage1().setChannel(row, column, 0, 252);
                action_data.getInputImage1().setChannel(row, column, 1, 209);
                action_data.getInputImage1().setChannel(row, column, 2, 22);
            }
            else{
                action_data.getInputImage1().setChannel(row, column, 0, 206);
                action_data.getInputImage1().setChannel(row, column, 1, 17);
                action_data.getInputImage1().setChannel(row, column, 2, 38);
            }
        }
    }
}

void setSize( ActionData& action_data ){
    int height = getInteger(action_data, "Height? ");
    int width = getInteger(action_data, "Width? ");
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);

} //Use getInteger to ask the user for the “Height? ” and “Width? “, and set the height and width of the input image 1.

void setMaxColorValue( ActionData& action_data ){
    int mcv = getInteger(action_data, "Max color value? ");
    action_data.getInputImage1().setMaxColorValue(mcv);
}// Use getInteger to ask the user for the “Max color value? ” and set the maximum color value of the input image 1.

void setChannel( ActionData& action_data ){
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int channel = getInteger(action_data, "Channel? ");
    int value = getInteger(action_data, "Value? ");
    action_data.getInputImage1().setChannel(row, column, channel, value);
}// Use getInteger to ask the user for “Row? “, “Column? “, “Channel? “, and “Value? “, then the set the channel value in input image 1.

void setPixel( ActionData& action_data ){
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");
    action_data.getInputImage1().setPixel(row, column, red, green, blue);
} //Use getInteger to ask the user for “Row? “, “Column? “, “Red? “, “Green? “, and “Blue? “, then the set the values in input image 1.

void clearAll( ActionData& action_data ){
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++){
        for (int column = 0; column < action_data.getInputImage1().getWidth(); column++){
    action_data.getInputImage1().setPixel(row, column, 0,0,0);
    }
    }
} //Set all pixels in input image 1 to have the color (0,0,0).

void drawCircle(ActionData& action_data){
    int centerR = getInteger(action_data, "Center Row? ");
    int centerC = getInteger(action_data, "Center Column? ");
    int radius = getInteger(action_data, "Radius? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++){
        for(int column = 0; column < action_data.getInputImage1().getWidth(); column++){
            int circleRow = row - centerR; 
            int circleColumn = column - centerC;
            double size = std::sqrt((circleRow * circleRow)+(circleColumn * circleColumn));
            if (size <= radius){
                action_data.getInputImage1().setPixel(row, column, red, green, blue);
            }
        }
    }


} //Asks the user for “Center Row? “, “Center Column? “, “Radius? “, “Red? “, “Green? “, and “Blue? “.
// Then fills in a circle shape with the color specified by the red, green and blue. All pixels that are no 
//more than radius pixels from the center should be set. Distance is calculated as the square root of the sum
// of row difference squared and column difference squared. You could #include <cmath> and use std::sqrt( ) to 
//calculate the square root, or use the math trick shown in class. Use multiplication (*) to square values. Note
// that std::sqrt() will return a double value, so use the correct variable type to store the result. Make changes to the input image 1.


void drawBox(ActionData& action_data){
    int topRow = getInteger(action_data, "Top Row? ");
    int leftColumn = getInteger(action_data, "Left Column? ");
    int bottomRow = getInteger(action_data, "Bottom Row? ");
    int rightColumn = getInteger(action_data, "Right Column? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");
    for (int row = topRow; row <= bottomRow; row++){
        for(int column = leftColumn; column <= rightColumn; column++){
            action_data.getInputImage1().setPixel(row, column, red, green, blue);
        }
    }
}// Asks the user for “Top Row? “, “Left Column? “, “Bottom Row? “, 
//“Right Column?”, “Red? “, “Green? “, and “Blue? “. Then fills in a rectangle shape
// with the color specified by the red, green and blue. All pixels that have a row between 
//the top and bottom row (inclusive) and between the left and right column (inclusive) should
// be set. Make changes to the input image 1.

void drawSquare(ActionData& action_data){
    int rowCenter = getInteger(action_data, "Row? ");
    int columnCenter = getInteger(action_data, "Column? ");
    int size = getInteger(action_data, "Size? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");
    for (int row = size; row <= rowCenter*2; row++ ){
        for (int column = size; column <= columnCenter*2; column ++)
        action_data.getInputImage1().setPixel(row, column, red, green, blue);
    }

}