#ifndef PASSWORDMANAGER_H_
#define PASSWORDMANAGER_H_

#pragma once
#include "HelperFunctions.hpp"
#include <unordered_map>
#include <memory>
#include <vector>

class PasswordManager
{
private:
    unique_ptr<unordered_map<string, std::vector<Credentials>>> services;

public:
    PasswordManager();
    ~PasswordManager();
    void setCredentials(std::string service, Credentials credentials);
    void displayAllServices();
    void displayOneService(std::string service);
    void AddService(std::string service);
    void AddCredentials();
    void getServices();
};

// PasswordManager::PasswordManager()

// :services(make_unique<unordered_map<string, Credentials>>()) {}

// PasswordManager::~PasswordManager() {

// }

// Credentials PasswordManager:: getCredentials(string service) {

// }

#endif