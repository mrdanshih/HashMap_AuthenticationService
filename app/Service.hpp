//
// Created by Daniel Shih on 3/19/17.
//
#include "HashMap.hpp"

#ifndef SERVICE_HPP

#define SERVICE_HPP

class Service{
public:
    Service();

    void runService();


private:
    bool debugMode;

    HashMap database;
    bool processRegularCommand(std::string line);
    bool processDebugCommand(std::string line);

    std::string processCreate(std::istringstream& stream);
    std::string processLogin(std::istringstream& stream);
    std::string processRemove(std::istringstream& stream);

};





#endif //SERVICE_HPP
