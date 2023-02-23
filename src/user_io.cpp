#include <iostream>
#include <string>
#include "image_menu.h"
#include "Image.h"
#include "ActionData.h"



std::string getString(ActionData& action_data, const std::string& prompt){
    std::string store_str;
    action_data.getOS() << prompt;
    action_data.getIS() >> store_str;
    return store_str; 
}
int getInteger( ActionData& action_data, const std::string& prompt  ){
    int store_int;
    action_data.getOS() << prompt;
    action_data.getIS() >> store_int;
    return store_int; 
}
double getDouble( ActionData& action_data, const std::string& prompt  ){
    double store_double;
    action_data.getOS() << prompt;
    action_data.getIS() >> store_double;
    return store_double;
}
int askQuestions3(ActionData& action_data){
    std::string color = getString(action_data, ("What is your favorite color? "));
    int get_int = getInteger(action_data,("What is your favorite integer? "));
    double get_dub = getDouble(action_data, ("What is your favorite number? "));
    for(int i = 0; i < get_int; i++){
        action_data.getOS() << i+1 << " " << color << " " << get_dub<< std::endl;
    }
    return get_int;
}

std::string getChoice( ActionData& action_data ){
    return getString(action_data, ("Choice? "));
}

void commentLine( ActionData& action_data ){
    unsigned char byte;
    bool continued = true;
    while(continued == true){
        action_data.getIS().read((char *)&byte, 1);
        if (!action_data.getIS().good() || byte == '\n'){
            continued = false;
    }
    }
    return;
}

void quit(ActionData& action_data){
    return action_data.setDone();
}

int askUncleBuckQuestions(ActionData& action_data){
    std::string city = getString(action_data, ("Where do you live? "));
    std::string rent = getString(action_data, ("Own or rent? "));
    int record = getInteger(action_data, ("What is your record for consecutive questions asked? "));
    std::string value;
    if (record < 20 ){
        value = "pretty good";
    }
    else{
        value = "okay";
    }
    action_data.getOS() << record << " is " << value << ". " << "Enjoy " << rent << "ing in the " << city << std::endl;
    return record; 
}