#ifndef _MENUDATA_H_
#define _MENUDATA_H_

#include <map>
#include <iostream>
#include <vector>
#include "ActionData.h"

typedef void (*ActionFunctionType)(ActionData& action_data);

class MenuData{
public:
    MenuData(); 
    void addAction(const std::string& name, ActionFunctionType func, const std::string& description); 
    const std::vector<std::string>& getNames() const; 
    ActionFunctionType getFunction(const std::string& name);
    const std::string& getDescription(const std::string& name); 
private:
    std::vector<std::string> commandName; // This is a collection of the command names the user can type.
    std::map<std::string, ActionFunctionType> mapAction; //This is a map from command name to action function.
    std::map<std::string, std::string> mapCommand; //This is a map from command name to command description.
};
#endif