#include "MenuData.h"

MenuData::MenuData(){}; //All data members have default constructors that do the right thing, so no initialization of the data members is necessary. The constructor must be implemented, it is just empty.

void MenuData::addAction(const std::string& name, ActionFunctionType func, const std::string& description){
    commandName.push_back(name);
    mapAction[name] = func;
    mapCommand[name] = description;
} //Append name to the collection of names, insert func in the action function map, with name as the key, and insert description into the description map with name as the key.

const std::vector<std::string>& MenuData::getNames() const{
    return commandName;
} //Return the name collection data member.

ActionFunctionType MenuData::getFunction(const std::string& name){
    if (mapAction.count(name) != 0){
        return mapAction[name];
    }
    else{
        return 0;
        }

} //If name is a key in the action function map, return the function associated with it. If name is not a key, return 0.

std::string empty1;

const std::string& MenuData::getDescription(const std::string& name){
    if (mapCommand.count(name)!= 0){
        return mapCommand[name];
    }
    else{
        static std::string empty1 = "";
        return empty1;
    }
} //If name is a key in the description map, return the description associated with it. If name is not a key, return the empty string. Use a static std::string variable that is initialized to the empty string.
