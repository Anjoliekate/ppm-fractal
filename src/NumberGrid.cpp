#include "NumberGrid.h"
#include <vector>

NumberGrid::NumberGrid( )
: gridHeight(300), gridWidth(400), maxGridVal(255), gridNum((gridHeight * gridWidth), 0) {}
//Initializes the grid to a height of 300, width of 400, max number of 255, and fills the grid with 0s.

NumberGrid::NumberGrid( const int& height, const int& width ) 
: gridHeight(height), gridWidth(width), maxGridVal(255), gridNum((gridHeight * gridWidth), 0) {} 
//Initializes the grid to the height specified, width specified, max number of 255, and fills the grid with 0s.

NumberGrid::~NumberGrid(){}
//This destructor only needs an empty block of code. But, it must exist.

int NumberGrid::getHeight( ) const{
    return gridHeight;
} //Returns the height of the grid.
int NumberGrid::getWidth( ) const{
    return gridWidth;
} //Returns the width of the grid.

int NumberGrid::getMaxNumber( ) const{
    return maxGridVal;
} //Returns the maximum number allowed in the grid.

void NumberGrid::setGridSize( const int& height, const int& width ){
    if(height >= 2 && width >= 2){
    gridHeight = height;
    gridWidth = width;
    gridNum.resize(gridHeight * gridWidth);
}
} //Sets the height and width of the grid, and resizes the grid storage vector correctly.
// Only makes any of these changes if the height and width are both at least 2. The state of 
//the grid values after the resize is undefined.

void NumberGrid::setMaxNumber( const int& number ){
if (number >= 0){
        maxGridVal = number;
    }
} //Change the maximum value allowed in the grid. Only make changes if the
// new maximum allowed value is at least 0. The state of grid values that are 
//larger than the new maximum allowed value is undefined.

const std::vector< int >& NumberGrid::getNumbers( ) const{
    return gridNum;
} //Returns a reference to the std::vector of grid values.

int NumberGrid::index( const int& row, const int& column ) const{
    int index = (row * gridWidth) + column;
    return index;
} //Returns the index in the grid value vector calculated from the formula: row times width plus column.

bool NumberGrid::indexValid( const int& row, const int& column ) const{
    return row < gridHeight && row >= 0 && column < gridWidth && column >= 0;
    
} //Returns true if row and column are both within the range of the grid. Otherwise returns false.

bool NumberGrid::numberValid( const int& number ) const{
    return (number >= 0 && number <= maxGridVal);
} //Returns true if the number is non-negative and is no larger than the maximum allowed value.

int NumberGrid::getNumber( const int& row, const int& column ) const{
    if (indexValid(row, column)){
        return gridNum[index(row, column)];
    }
    else{
        return -1;
    }
} //Returns a number from the grid, at the position specified by the row and column. If the position is not valid, returns -1.

void NumberGrid::setNumber( const int& row, const int& column, const int& number ){
    if (indexValid(row, column) && numberValid(number)){
        gridNum[index(row, column)] = number;
    }
}// Sets a number in the grid, at the position specified by the row and column. The value is 
//specified by the number parameter. Only makes a change if the position is valid and the number is valid.

void NumberGrid::setPPM( PPM& ppm ) const{
    ppm.setHeight(gridHeight);
    ppm.setWidth(gridWidth);
    ppm.setMaxColorValue(63);
    for (int row = 0; row < gridHeight; row++){
        for (int column = 0; column < gridWidth; column++){
            if (getNumber(row, column) == 0){
            ppm.setPixel(row, column, 0, 0, 0);
            }
            else if (getNumber(row, column) == maxGridVal){
                ppm.setPixel(row, column, 63, 31, 31);
            }
            else if(getNumber(row, column) % 8 == 0){
                ppm.setPixel(row, column, 63, 63, 63);
            }
            else if(getNumber(row, column) % 8 == 1){
                ppm.setPixel(row, column, 63, 31, 31);
            }
            else if(getNumber(row, column) % 8 == 2){
                ppm.setPixel(row, column, 63, 63, 31);
            }
            else if(getNumber(row, column) % 8 == 3){
                ppm.setPixel(row, column, 31, 63, 31);
            }
            else if(getNumber(row, column) % 8 == 4){
                ppm.setPixel(row, column, 0, 0, 0);
            }
            else if(getNumber(row, column) % 8 == 5){
                ppm.setPixel(row, column, 31, 63, 63);
            }
            else if(getNumber(row, column) % 8 == 6){
                ppm.setPixel(row, column, 31, 31, 63);

            }
            else if(getNumber(row, column) % 8 == 7){
                ppm.setPixel(row, column, 63, 31, 63);
            }
        }
    }
    
} //Configures the meta data of the PPM object so that the height and width match that 
//of the number grid. Sets the maximum color value of the PPM to 63. Finally, for each pixel
// in the PPM object, sets the color based on the table below.