#include <iostream>
#include "image_menu.h"
#include <ctime>

int main(){
    return imageMenu(std::cin, std::cout);
    std::srand(std::time(0));
}