/*
#include "JuliaSet.h"

JuliaSet::JuliaSet( )
: mA(-0.650492), mB(-0.478235){} //Uses ComplexFractal’s default constructor. 
//Additionally sets a to -0.650492, b to -0.478235, and maximum number count to 255.

JuliaSet::JuliaSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b )
: ComplexFractal(height, width, min_x, min_y, max_x, max_y) {}// Constructor. Sets up the ComplexFractal and JuliaSet data members from parameters.

JuliaSet::~JuliaSet( ){} //Must exist, but has empty code block.

double JuliaSet::getA( ) const{
    return mA;
} //Return the a parameter for the Julia set.

double JuliaSet::getB( ) const{
    return mB;
} //Return the b parameter for the Julia set.

void JuliaSet::setParameters( const double& a, const double& b ){
    if (a >= -2.0 && a <= 2.0 && b >= -2.0 && b <= 2.0){
        mA = a;
        mB = b;
    }
} //Sets a and b parameters. Only allows values in the range -2.0 to 2.0 for each. If either is out of range, change nothing.

void JuliaSet::calculateNextPoint( const double x0, const double y0, double& x1, double &y1 ) const{
    x1 = x0*x0 - y0*y0 +mA;
    y1 = 2*x0*y0 + mB;

} //Calculate the next escape point after x0, y0 and store in x1, y1. Note that x1 and y1 are return by reference.
// This is the Julia set function x',y' = f(x,y).

int JuliaSet::calculatePlaneEscapeCount( const double& x0, const double& y0 ) const{

} //Calculate the number of iterations required for x0, y0 to escape. The return value
// should be in the range 0 to maximum escape count, inclusive. 0 means immediately escaped, 
//before any applications of the function. Maximum escape count means never escaped, or escaped on the last step. 
//Escape means the distance from the origin is more than 2.

int JuliaSet::calculateNumber( const int& row, const int& column ) const{
    int iteration = 0;

} //Calculate the number of iterations required for row, column to escape. The return value should be 
//in the range 0 to maximum escape count, inclusive. 0 means immediately escaped. Maximum escape count
// means never escaped, or escaped on the last step. If row or column is out of range, return -1. 
//Should use calculatePlaneCoordinatesFromPixelCoordinates() and calculatePlaneEscapeCount().
*/