#include "MandelbrotSet.h"
#include <cmath>

MandelbrotSet::MandelbrotSet( )
:ComplexFractal(){} //The default constructor, chain constructs via the ComplexFractal default constructor.

MandelbrotSet::MandelbrotSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y )
: ComplexFractal(height, width, min_x, max_x, min_y, max_y){} //Passes arguments on to the ComplexFractal constructor.

 MandelbrotSet::~MandelbrotSet( ){}// Does nothing, empty code block.

void MandelbrotSet::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const{
    x1 = x0*x0 - y0*y0 + a;
    y1 = 2*x0*y0 + b;
} //Calculates x1 and y1 using the function described above for the Mandelbrot set.

int MandelbrotSet::calculatePlaneEscapeCount( const double& a, const double& b ) const{
    double x0 = a;
    double y0 = b;
    int escape_count = 0;
    while ((x0 * x0) + (y0 * y0) <= 4 && escape_count < maxGridVal ){
        double x1 = x0;
        double y1 = y0;
        calculateNextPoint(x1, y1, a, b, x0, y0);
        escape_count++;
    }
    return escape_count;
}// Uses calculateNextPoint to find the escape count for the point at (a,b). 
//The first iteration from x,y = 0,0 to x,y = a,b doesn’t count as an iteration.
int MandelbrotSet::calculateNumber( const int& row, const int& column ) const{
    if (row < 0 || row >= gridHeight || column < 0 || column >= gridWidth){
        return -1;
    }
    else{
        double a, b;
        calculatePlaneCoordinatesFromPixelCoordinates(row, column, a, b);
        int escape_count = calculatePlaneEscapeCount(a, b);
        return escape_count;
    }

} //Uses other methods to find the plane coordinate of the pixel at row, column
// and to calculate the escape count. Returns the count. If row, column isn’t valid, then returns -1.

MandelbrotPower::MandelbrotPower()
: nextPoint(2.0) {}//The default constructor, does constructor chaining to the parent class. Sets the default power to 2.0.

MandelbrotPower::~MandelbrotPower(){} //The required but empty destructor.

double MandelbrotPower::getPower() const{
    return nextPoint;
} //Returns the power data member.

void MandelbrotPower::setPower(const double& power){
    nextPoint = power;
} //Modifies the power data member.

void MandelbrotPower::calculateNextPoint(const double x0, const double y0, const double& a, const double& b, double& x1, double &y1) const{
    double r = sqrt( x0*x0 + y0*y0 );
    double theta = atan2( y0, x0 );
    x1 = std::pow(r , nextPoint) * cos( nextPoint * theta ) + a;
    y1 = std::pow(r, nextPoint) * sin( nextPoint * theta ) + b;
} //Apply the formulas listed above, with x' = x1 y' = y1, x = x0, y = y0, where a,b are the original point.