#include <string>
#include <iostream>
#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt);
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt);
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt);
int askQuestions3(std::istream& is, std::ostream& os);
int assignment1( std::istream& is, std::ostream& os);

#endif /*_IMAGE_MENU_H_*/
