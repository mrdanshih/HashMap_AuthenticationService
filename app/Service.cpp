//
// Created by Daniel Shih on 3/19/17.
//

#include "Service.hpp"
#include <iostream>
#include <sstream>

Service::Service():
        debugMode{false}
{

}

void Service::runService() {

    while(true){
        std::string line;
        std::getline(std::cin, line);

        /*First tries to process the line as a Debug command.
         * If the result if False, then the Debug command
         * was either invalid or not valid because
         * debug mode was off. Thus, if it is False,
         * the line should be processed as a regular command.
         */

        bool successfulDebugProcessed = processDebugCommand(line);

        if(!successfulDebugProcessed){
            bool toContinue = processRegularCommand(line);

            if(!toContinue){
                break;
            }
        }

    }

}

bool Service::processDebugCommand(std::string line) {
    /*Returns whether or not the command was processed as Debug Command
     * AKA, if this function returns false, then that means
     * the program should process the command as a regular command.
     *
     * If it returns true, then that means a Debug command was
     * successfully processed.
     * */

    if(line == "DEBUG ON"){
        if(debugMode){
            std::cout << "ON ALREADY" << std::endl;
        }else{
            debugMode = true;
            std::cout << "ON NOW" << std::endl;
        }
        return true;

    }else if(line == "DEBUG OFF"){
        if(debugMode){
            debugMode = false;
            std::cout << "OFF NOW" << std::endl;
        }else{
            std::cout << "OFF ALREADY" << std::endl;
        }
        return true;

    }else if(line == "LOGIN COUNT" || line == "BUCKET COUNT" ||
            line == "LOAD FACTOR" || line == "MAX BUCKET SIZE"){

        if(debugMode){
            if(line == "LOGIN COUNT"){
                std::cout << database.size() << std::endl;
                return true;

            }else if(line == "BUCKET COUNT"){
                std::cout << database.bucketCount() << std::endl;
                return true;

            }else if(line == "LOAD FACTOR"){
                std::cout << database.loadFactor() << std::endl;
                return true;

            }else if(line == "MAX BUCKET SIZE"){
                std::cout << database.maxBucketSize() << std::endl;
                return true;
            }
        }else{
            std::cout << "INVALID";
            return true;
        }

    }

    return false;
}

bool Service::processRegularCommand(std::string line) {
    //Returns whether the program should continue or not (depends on QUIT)

    std::istringstream stream(line);

    std::string firstToken;
    stream >> firstToken;

    if (firstToken == "QUIT") {
        std::cout << "GOODBYE";
        return false;

    } else if (firstToken == "CREATE") {
        std::cout << processCreate(stream) << std::endl;

    } else if (firstToken == "LOGIN") {
        std::cout << processLogin(stream) << std::endl;
    } else if (firstToken == "REMOVE"){
        std::cout << processRemove(stream) << std::endl;
    } else if (firstToken == "CLEAR"){
        database = HashMap();
        std::cout << "CLEARED" << std::endl;

    } else{
        std::cout << "INVALID" << std::endl;
    }

    return true;
}



std::string Service::processCreate(std::istringstream& stream) {
    std::string username;
    stream >> username;

    std::string password;
    stream >> password;

    if(username.length() > 0 && password.length() > 0){
        if(database.contains(username)){
            return "EXISTS";
        }else{
            database.add(username, password);
            return "CREATED";
        }
    }

    return "INVALID";
}

std::string Service::processLogin(std::istringstream& stream) {
    std::string username;
    stream >> username;

    std::string password;
    stream >> password;

    if(database.contains(username)){
        if(database.value(username) == password){
            return "SUCCEEDED";
        }
    }

    return "FAILED";
}

std::string Service::processRemove(std::istringstream& stream) {
    std::string username;
    stream >> username;

    if(database.contains(username)){
        database.remove(username);
        return "REMOVED";

    }else{
        return "NONEXISTENT";
    }
}


