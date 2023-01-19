#include <iostream>
#include "image_menu.h"

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt ){
    std::string store_str;
    os << prompt;
    is >> store_str;
    return store_str; 
}
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt ){
    int store_int;
    os << prompt;
    is >> store_int;
    return store_int; 
}
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt ){
    double store_double;
    os << prompt;
    is >> store_double;
    return store_double;
}
int askQuestions3(std::istream& is, std::ostream& os){
    std::string color = getString(is, os, "What is your favorite color? ");
    int get_int = getInteger(is, os, "What is your favorite integer? ");
    double get_dub = getDouble(is, os, "What is your favorite number? ");
    for(int i = 1; i = get_dub; i++){
        std::cout << "" << i << " " << color << " " << get_dub<< "" << std::endl;
    }

}