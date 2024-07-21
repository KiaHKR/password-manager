#ifndef PASSWORDMANAGER_HPP_
#define PASSWORDMANAGER_HPP_

#include "HelperFunctions.hpp"
#include <unordered_map>
#include <memory>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <algorithm>

class PasswordManager
{
private:
    std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services;

public:
    PasswordManager();
    ~PasswordManager();
    void addNewCredentials();
    void updateCredentials();
    void deleteCredentials();
    void deleteService();
    void displayAllServices();
    void displayOneService();
    std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> getServices();
};

#endif