#include "ActionData.h"

ActionData::ActionData(std::istream& is, std::ostream& os)
:IS(is), OS(os), Quit(false){}; //The constructor initializes the input and output stream data members from the two parameters. The : initialization syntax must be used for this initialization. Also initializes the Boolean data member to false. The PPM data members do not need any initialization. Their default constructors will automatically initialize them.

std::istream& ActionData::getIS(){
    return IS;
} //Returns the input stream data member.

std::ostream& ActionData::getOS(){
    return OS;
} //Returns the output stream data member.

PPM& ActionData::getInputImage1(){
    return inputImage1;
} //Returns the input image 1 data member.

PPM& ActionData::getInputImage2(){
    return inputImage2;
} //Returns the input image 2 data member.

PPM& ActionData::getOutputImage(){
    return outputImage;
} //Returns the output image data member.

bool ActionData::getDone() const //Returns the Boolean data member.
{return Quit;}

void ActionData::setDone(){
    Quit = true;
} //Sets the Boolean data member to true.

