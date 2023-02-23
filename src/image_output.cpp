#include <iostream>
#include <fstream>
#include "Image.h"
#include "image_menu.h"
#include "PPM.h"
#include "ActionData.h"

void drawAsciiImage( ActionData& action_data ){
    int height = action_data.getOutputImage().getHeight();
    int width = action_data.getOutputImage().getWidth();
    for(int row = 0; row < height; row++){
        for(int column = 0; column < width; column++){
            int r = action_data.getOutputImage().getChannel(row, column, 0);
            int g = action_data.getOutputImage().getChannel(row, column, 1);
            int b = action_data.getOutputImage().getChannel(row, column, 2);
            double color = (r + g + b)/765.0;
            if (color >= 1.0){
                action_data.getOS() << "@";
            }
            else if (color >= 0.9){
                action_data.getOS() << "#";
            }
            else if(color >= 0.8){
                action_data.getOS() << "%";
            }
            else if(color >= 0.7){
                action_data.getOS() << "*";
            }
            else if (color >= 0.6){
                action_data.getOS() <<"|";
            }
            else if(color >= 0.5){
                action_data.getOS() << "+";
            }
            else if(color >= 0.4){
                action_data.getOS() << ";";
            }
            else if(color >= 0.3){
                action_data.getOS() << "~";
            }
            else if(color >= 0.2){
                action_data.getOS() << "-";
            }
            else if(color >= 0.1){
                action_data.getOS() << ".";
            }
            else if(color >= 0.0){
                action_data.getOS() << " ";
            }
        }
        action_data.getOS() << std::endl;
    }
}

    void writeUserImage(ActionData& action_data){
        std::string name_of_file;
        name_of_file = getString(action_data, "Output filename? ");
        std::ofstream file(name_of_file, std::ios::binary);
        action_data.getOutputImage().writeStream(file);
        file.close();
       
    }

    void copyImage(ActionData& action_data){
        action_data.getOutputImage() = action_data.getInputImage1();
    }

    void readUserImage1( ActionData& action_data ){
        std::string fileName = getString(action_data, "Input filename? ");
        std::ifstream file(fileName);
        if (!file.is_open()){
            action_data.getOS() << "'" << fileName << "' could not be opened." << std::endl;
            
        }
        else{
            action_data.getInputImage1().readStream(file);
            file.close();
        }

    }//Uses getString to ask the user for the name of an existing PPM file to be read, using 
    //“Input filename? ” as the prompt. Opens the file as an std::ifstream, then uses readStream() to read the file into 
    //the input image 1. If the file does not open correctly, report to the that the file could not be opened. For example, if the file was 
    //named “foo.ppm”, then the message should be “‘foo.ppm’ could not be opened.”
