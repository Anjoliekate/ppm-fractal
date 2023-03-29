#include "ComplexFractal.h"
#include <cmath>

ComplexFractal::ComplexFractal( )
: NumberGrid(200, 300), minX(-1.5), minY(-1.0), maxX(1.5), maxY(1.0), deltaX(0.01), deltaY(0.01) {

} //Default constructor. Sets up for a 301x201 grid. For the plane coordinates uses the 3x2 
//rectangle centered on the origin. Sets the default value for delta_x and delta_y to 0.01. 
//What values of min_x and max_x would give you a rectangle of width 3 and centered on the origin? Be sure to use constructor chaining.

ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y )
   : NumberGrid(height, width), minX(min_x),  minY(min_y), maxX(max_x), maxY(max_y){
} //Constructor. Sets up the NumberGrid and ComplexFractal data members from parameters. Be sure to use constructor chaining.

ComplexFractal::~ComplexFractal( ){}
 //Must exist, but has empty code block.

double ComplexFractal::getMinX( ) const{
    return minX;
} //Return the minimum X value for the plane coordinates.

double ComplexFractal::getMaxX( ) const{
    return maxX;
} //Return the maximum X value for the plane coordinates.

double ComplexFractal::getMinY( ) const{
    return minY;
} //Return the minimum Y value for the plane coordinates.

double ComplexFractal::getMaxY( ) const{
    return maxY;
} //Return the maximum Y value for the plane coordinates.

void ComplexFractal::setGridSize( const int& height, const int& width ){
    bool changed = false;
    if (width >= 2 && height >= 2){
        NumberGrid::setGridSize(height, width);
        changed = true;
    }
    if (changed){
        double dx = calculateDeltaX();
        double dy = calculateDeltaY();
        setDeltas(dx, dy);
    }
}// This method overrides the NumberGrid version. Only makes changes if both height 
//and width are at least 2. If so, it calls NumberGrid::setGridSize(). If a change is made,
// updates the values of delta x and delta y data members. Uses calculateDeltaX(), calculateDeltaY(), and setDeltas().

void ComplexFractal::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y ){
    bool changed = false;
    if (min_x <= 2.0 && min_x >= -2.0 && max_x <= 2.0 && max_x >= -2.0 && min_y <= 2.0 && min_y >= -2.0 && max_y <= 2.0 && max_y >= -2.0 && min_x != max_x && min_y != max_y){
        minX = min_x;
        maxX = max_x;
        minY = min_y;
        maxY = max_y;
        if (min_x > max_x ){
            minX = max_x;
            maxX = min_x;
            changed = true;
        }
        else if (min_y > max_y ){
            minY = max_y;
            maxY = min_y;
            changed = true;
        }

    }
    if (changed){
        double dx = calculateDeltaX();
        double dy = calculateDeltaY();
        setDeltas(dx, dy);
    }
} //Sets the 4 plane coordinates. Only makes a change if all of the coordinate values are between -2.0 and 2.0,
// inclusive. Only make changes if the minimum and maximum value for a dimension are different. If the minimum 
//value for a dimension is greater than the maximum value for the dimension, automatically swap them. If a change is made,
// updates the values of delta x and delta y data members. Uses calculateDeltaX(), calculateDeltaY(), and setDeltas().

double ComplexFractal::getDeltaX( ) const{
    return deltaX;
} //Returns the horizontal delta value from the data member.

double ComplexFractal::getDeltaY( ) const{
    return deltaY;
} //Returns the vertical delta value from the data member.

void ComplexFractal::setDeltas( const double& delta_x, const double& delta_y ){
    if(delta_x >= 0 && delta_y >= 0 ){
    deltaY = delta_y;
    deltaX = delta_x;
    }    
} //Assigns the deltas to data members. Only assigns if both values are positive.

double ComplexFractal::calculateDeltaY( ) const{
    double delta_y = ((maxY - minY) / (getHeight() - 1));
    return delta_y; 
} //Calculate the vertical plane distance between neighboring pixel rows. This is the delta
// value discussed above. Note this method calculates the value and returns it. It does not set the data member.

double ComplexFractal::calculateDeltaX( ) const{
    double delta_x = ((maxX- minX)/(getWidth() - 1));
    return delta_x;
} //Calculate the horizontal plane distance between neighboring pixel columns. This is the delta value discussed
// above. Note this method calculates the value and returns it. It does not set the data member.

double ComplexFractal::calculatePlaneXFromPixelColumn( const int& column ) const{
    if (column >= 0 || column < getWidth()){
        return 0;
    }
    else{
        double x  = minX + column * deltaX;
        return x;
    }
} //Calculate the plane x value for a given column. If the column index is out of range (if column is less than 
//zero or column is greater than or equal to the grid width), return 0. Do not call calculateDeltaX() here. Use getDeltaX() 
//or directly access the data member. The value should have already been calculated previously.

double ComplexFractal::calculatePlaneYFromPixelRow( const int& row ) const{
    if (row < 0 || row >= getHeight()){
        return 0;
    }
    else{
        double y = maxY - row * deltaY;
        return y;
    }

} //Calculate the plane y value for a given row. If the row index is out of range (if row is less than zero or row 
//is greater than or equal to the grid height), return 0. Do not call calculateDeltaY() here. Use getDeltaY() or directly 
//access the data member. The value should have already been calculated previously.

void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const{
    x = calculatePlaneXFromPixelColumn(column);
    y = calculatePlaneYFromPixelRow(row);
    if(x == 0 || y == 0){
        x = 0;
        y = 0;
    }
} //Sets x and y to the plane coordinates for the row and column. If either row or column is out of range, set both x and y to 0.
// Notice x and y are return by reference.

int ComplexFractal::calculateNumber( const int& row, const int& column ) const{
    double x;
    double y;
    calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
    int int_val;
    if(x == 0 || y == 0){
        int_val = -1;
    }
    else{
        int_val = std::abs(getMaxNumber() * std::sin(10*x) * std::cos(10*y));
    }
    return int_val;
} //If the row and column will make a valid index, calculate values for x and y from row and column. Then use the formula:
// std::abs(getMaxNumber() * std::sin(10*x) * std::cos(10*y)) to calculate an integer value. Return this value. If row and 
//column are not valid, return -1.