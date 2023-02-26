#include <string>
#include <iostream>
#include "Image.h"
#include "PPM.h"
#include "ActionData.h"
#include "MenuData.h"
#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_

//questions_3
std::string getString(ActionData& action_data, const std::string& prompt);
int getInteger( ActionData& action_data, const std::string& prompt);
double getDouble( ActionData& action_data, const std::string& prompt);
int askQuestions3(ActionData& action_data);
int assignment1( std::istream& is, std::ostream& os);

//ascii_image
void drawAsciiImage( ActionData& action_data);
void diagonalQuadPattern( ActionData& action_data);
int assignment2( std::istream& is, std::ostream& os);

//image_file | may need to hash out for testing purposes
void writeUserImage( ActionData& action_data );
void stripedDiagonalPattern( ActionData& action_data);
int assignment3( std::istream& is, std::ostream& os );

//ppm menu
std::string getChoice( ActionData& action_data ); 
void commentLine( ActionData& action_data ); 
void quit(ActionData& action_data);
void clearAll(ActionData& action_data); 
void setSize( ActionData& action_data );
void setMaxColorValue( ActionData& action_data );
void setChannel( ActionData& action_data );
void setPixel( ActionData& action_data );
void copyImage(ActionData& action_data);
void readUserImage1( ActionData& action_data );
void showMenu( MenuData& menu_data, ActionData& action_data );
void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data);
void configureMenu( MenuData& menu_data );
int imageMenu(std::istream& is, std::ostream& os); 


//exam 1
void flagRomaniaPattern( ActionData& action_data );
int flag_romania( std::istream& is, std::ostream& os );

int askUncleBuckQuestions(ActionData& action_data);
int buck( std::istream& is, std::ostream& os );



#endif /*_IMAGE_MENU_H_*/
