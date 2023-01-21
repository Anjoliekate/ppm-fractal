#include <string>
#include <iostream>
#ifndef IMAGE_MENU
#define IMAGE_MENU

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt);
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt);
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt);
int askQuestions3(std::istream& is, std::ostream& os);
int assignment1( std::istream& is, std::ostream& os);

#endif /*IMAGE_MENU*/