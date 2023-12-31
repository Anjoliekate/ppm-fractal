#include <iostream>
#include "image_menu.h"
#include "ComplexFractal.h"
#include "JuliaSet.h"
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

void configureGrid(ActionData& action_data){
    int gridHeight = getInteger(action_data, "Grid Height? ");
    int gridWidth = getInteger(action_data, "Grid Width? ");
    int gridMaxValue = getInteger(action_data, "Grid Max Value? ");
    action_data.getGrid().setGridSize(gridHeight, gridWidth);
    action_data.getGrid().setMaxNumber(gridMaxValue);

} //Prompt the user for integers “Grid Height? “, “Grid Width? “, and “Grid Max Value? “.
// Use them to configure the NumberGrid object in the ActionData.

void setGrid(ActionData& action_data){
    int gridRow = getInteger(action_data, "Grid Row? ");
    int gridColumn = getInteger(action_data, "Grid Column? ");
    int gridValue = getInteger(action_data,"Grid Value? " );
    action_data.getGrid().setNumber(gridRow, gridColumn, gridValue);
} //Prompt the user for integers “Grid Row? “, “Grid Column? “, and “Grid Value? “. 
//Use them to set a number in the NumberGrid object of ActionData.

void applyGrid(ActionData& action_data){
    action_data.getGrid().setPPM(action_data.getOutputImage());
} //Configure the output image using the number grid.

void setColorTableSize(ActionData& action_data){
    int size = getInteger(action_data, "Size? ");
    action_data.getTable().setNumberOfColors(size);
}
//Asks the user for the “Size? “, then applies it to the color table.

void setColor(ActionData& action_data){
    int position = getInteger(action_data, "Position? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");
    action_data.getTable()[position].setChannel(0, red);
    action_data.getTable()[position].setChannel(1, green);
    action_data.getTable()[position].setChannel(2, blue);
}
// Asks the user for “Position? “, “Red? “, “Green? “, and “Blue? “.
// Then uses them to set a color at the specified position in the color table.

void setRandomColor(ActionData& action_data){//comeback to this
    int position = getInteger(action_data, "Position? ");
    action_data.getTable().setRandomColor(255, position);

}
// Asks the user for “Position? “, then uses setRandomColor() to set a
// random color at that position in the color table. Use 255 for the maximum color value.

void setColorGradient(ActionData& action_data){
    int firstPosition = getInteger(action_data, "First position? ");
    int firstRed = getInteger(action_data, "First red? ");
    int firstGreen = getInteger(action_data, "First green? ");
    int firstBlue = getInteger(action_data, "First blue? ");
    int secondPosition = getInteger(action_data, "Second position? ");
    int secondRed = getInteger(action_data, "Second red? ");
    int secondGreen = getInteger(action_data, "Second green? ");
    int secondBlue = getInteger(action_data, "Second blue? ");
    Color firstColor;
    firstColor.setRed(firstRed);
    firstColor.setGreen(firstGreen);
    firstColor.setBlue(firstBlue);
    Color secondColor;
    secondColor.setRed(secondRed);
    secondColor.setGreen(secondGreen);
    secondColor.setBlue(secondBlue);
    action_data.getTable().insertGradient(firstColor, secondColor, firstPosition, secondPosition);
}
// Asks the user for “First position? “, “First red? “, “First green? “, “First blue? “,
// “Second position? “, “Second red? “, “Second green? ” and “Second blue? “. The uses 
//them to insertGradient() in the color table.

void setFractalPlaneSize(ActionData& action_data){

    //if (grid is complexFractal object){
    ComplexFractal *fractal = dynamic_cast<ComplexFractal *>(&action_data.getGrid());
    if (fractal != 0 ){
            double min_x = getDouble(action_data, "Min X? ");
            double max_x = getDouble(action_data, "Max X? ");
            double min_y = getDouble(action_data, "Min Y? ");
            double max_y = getDouble(action_data, "Max Y? ");
        (*fractal).setPlaneSize(min_x, max_x, min_y, max_y);
        
    }
    else{
    action_data.getOS() << "Not a ComplexFractal object. Can't set plane size.\n";
    }
//  else{ os << "Not a ComplexFractal object"}
} //Asks the user for the doubles “Min X? “, “Max X? “, “Min Y? ” and “Max Y? “,
// then sets the plane size. Only does this work if the grid is actually a ComplexFractal object.
// Otherwise, gives a message “Not a ComplexFractal object. Can’t set plane size.”.

void calculateFractal(ActionData& action_data){
    action_data.getGrid().calculateAllNumbers();
} //Calculates all numbers for the grid stored in action_data.

void applyGridColorTable(ActionData& action_data){
    action_data.getGrid().setPPM(action_data.getOutputImage(), action_data.getTable());
}
// Uses the new setPPM method of the grid to set the output image PPM
// using color table. Note this is not a replacement for applyGrid, this is in
// addition to that function.

void setJuliaParameters(ActionData& action_data){
    JuliaSet *js = dynamic_cast<JuliaSet *>(&action_data.getGrid());
    if (js != 0 ){
            double a = getDouble(action_data, "Parameter a? ");
            double b = getDouble(action_data, "Parameter b? ");
        (*js).setParameters(a, b);
        
    }
    else{
    action_data.getOS() << "Not a JuliaSet object. Can't set parameters.\n";
    }
}

void setMandelbrotPower(ActionData& action_data){
    MandelbrotPower *power = dynamic_cast<MandelbrotPower *>(&action_data.getGrid());
    if (power !=0){
        double p = getDouble(action_data, "Power? ");
        (*power).setPower(p);
    }
    else{
        action_data.getOS() << "Not a MandelbrotPower object. Can't set power.";
    }
} //Asks the user for a double precision floating point value “Power? “, and uses it to setPower on the mandelbrot power object, but only if the NumberGrid stored in the action data is actually a MandelbrotPower object. Otherwise sends a message to the action data output “Not a MandelbrotPower object. Can’t set power.”.
void calculateFractalSingleThread(ActionData& action_data){
    action_data.getGrid().NumberGrid::calculateAllNumbers();
}//This function calls the NumberGrid version of calculateAllNumbers instead of the ThreadedGrid version, which would 
//be the default. This is accomplished with this syntax: grid.NumberGrid::calculateAllNumbers(), assuming grid is a reference to a polymorphic NumberGrid object.

void setHueSaturationValueGradient(ActionData& action_data){
    int firstPosition = getInteger(action_data, "First position? ");
    int firstHue = getInteger(action_data, "First hue? ");
    int firstSat = getInteger(action_data, "First saturation? ");
    int firstVal = getInteger(action_data, "First value? ");
    int secondPosition = getInteger(action_data, "Second position? ");
    int secondHue = getInteger(action_data, "Second hue? ");
    int secondSat = getInteger(action_data, "Second saturation? ");
    int secondVal = getInteger(action_data, "Second value? ");
    Color firstColor;
    firstColor.setFromHSV(firstHue, firstSat, firstVal);
    Color secondColor;
    secondColor.setFromHSV(firstHue, firstSat, firstVal);
    action_data.getTable().insertGradient(firstColor, secondColor, firstPosition, secondPosition);
}//Asks the user for the information needed to insert a gradient in HSV, creates a pair of colors that are set from the HSV values,
// then inserts the HSV gradient into action_data’s color table. The prompts should be in this order: “First position? “, “First hue? “, 
//“First saturation? “, “First value? “, “Second position? “, “Second hue? “, “Second saturation? “, “Second value? “. Note that positions are 
//integers and HSV values are all floating point.