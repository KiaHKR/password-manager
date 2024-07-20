#ifndef PASSWORDMANAGER_HPP_
#define PASSWORDMANAGER_HPP_

#pragma once
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
    shared_ptr<unordered_map<string, std::vector<Credentials>>> services;

public:
    PasswordManager();
    ~PasswordManager();
    void addNewCredentials();
    void updateCredentials();
    void deleteCredentials(std::string service, Credentials credentials);
    void displayAllServices();
    void displayOneService(std::string service);
    shared_ptr<unordered_map<string, vector<Credentials>>> getServices();
};

// PasswordManager::PasswordManager()

// :services(make_unique<unordered_map<string, Credentials>>()) {}

// PasswordManager::~PasswordManager() {

// }

// Credentials PasswordManager:: getCredentials(string service) {

// }

#endif