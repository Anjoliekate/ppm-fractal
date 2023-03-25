#ifndef _ACTIONDATA_H_
#define _ACTIONDATA_H_
#include <iostream>
#include "PPM.h"
#include "NumberGrid.h"
#include "ColorTable.h"

class ActionData{

public:
    ActionData(std::istream& is, std::ostream& os); //The constructor initializes the input and output stream data members from the two parameters. The : initialization syntax must be used for this initialization. Also initializes the Boolean data member to false. The PPM data members do not need any initialization. Their default constructors will automatically initialize them.
    std::istream& getIS(); //Returns the input stream data member.
    std::ostream& getOS(); //Returns the output stream data member.
    PPM& getInputImage1(); //Returns the input image 1 data member.
    PPM& getInputImage2(); //Returns the input image 2 data member.
    PPM& getOutputImage(); //Returns the output image data member.
    bool getDone() const; //Returns the Boolean data member.
    void setDone(); //Sets the Boolean data member to true.
    ~ActionData(); 
    NumberGrid& getGrid();
    void setGrid(NumberGrid *grid);
    ColorTable& getTable(); 
    


    
private:
    std::istream& IS; //The application’s input stream. Notice that this data member should be declared as a reference (&). See the constructor for instructions to initialize it correctly.
    std::ostream& OS; //The application’s output stream. Notice that this data member should be declared as a reference (&). See the constructor for instructions to initialize it correctly.
    PPM inputImage1; //We will call this the “input image 1”. This is the PPM object that the user will act on most of the time. For example, if the user wants to set the width of the image, this is the object that will be changed.
    PPM inputImage2; //We will call this the “input image 2”. This is the PPM object that the user will act on some of the time. For example, if the user wants to merge two images, this will be the secondary image to merge.
    PPM outputImage; //We will call this the “output image”. This is the PPM object that will be used when the user writes an image to a file. The main way to change this object is for the user to ask for the input image 1 to be copied to it.
    bool Quit; //This data member keeps track of whether the user has asked for the application to be done (quit).
    NumberGrid *gridPointer;
    ColorTable colorTableObject;
};
#endif 