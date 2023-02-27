#include "image_menu.h"
#include "ActionData.h"
#include "PPM.h"

//prompts user for "Factor? " then uses input depending on operator

void plusEquals( ActionData& action_data ){
    action_data.getInputImage1()+= action_data.getInputImage2();

}
void minusEquals( ActionData& action_data ){
    action_data.getInputImage1()-= action_data.getInputImage2();
}
void timesEquals( ActionData& action_data ){
    double input2 = getDouble(action_data, "Factor? ");
    action_data.getInputImage1() *= input2;
}
void divideEquals( ActionData& action_data ){
    double input2 = getDouble(action_data, "Factor? ");
    action_data.getInputImage1() /= input2;
}
void plus( ActionData& action_data ){
    action_data.getOutputImage() = action_data.getInputImage1() + action_data.getInputImage2();

}
void minus( ActionData& action_data ){
        action_data.getOutputImage() = action_data.getInputImage1() - action_data.getInputImage2();

}
void times( ActionData& action_data ){
    double input2 = getDouble(action_data, "Factor? ");
    action_data.getOutputImage() = action_data.getInputImage1() * input2; 
}
void divide( ActionData& action_data ){
    double input2 = getDouble(action_data, "Factor? ");
    action_data.getOutputImage() = action_data.getInputImage1() / input2; 
}
void grayFromRed(ActionData& action_data){
    PPM gray;
    action_data.getInputImage1().grayFromRed(gray);
    action_data.getOutputImage() = gray;
} //Sets the output image to be the red to grayscale filtered copy of input image 1.
void grayFromGreen(ActionData& action_data){
    PPM gray;
    action_data.getInputImage1().grayFromGreen(gray);
    action_data.getOutputImage() = gray;
} 
//Sets the output image to be the green to grayscale filtered copy of input image 1.
void grayFromBlue(ActionData& action_data){
    PPM gray;
    action_data.getInputImage1().grayFromBlue(gray);
    action_data.getOutputImage() = gray;
}// Sets the output image to be the blue to grayscale filtered copy of input image 1.
void grayFromLinearColorimetric(ActionData& action_data){
    PPM gray;
    action_data.getInputImage1().grayFromLinearColorimetric(gray);
    action_data.getOutputImage() = gray;
} //Sets the output image to be the linear colorimetric grayscale filtered copy of input image 1.