#ifndef PASSWORDMANAGER_H_
#define PASSWORDMANAGER_H_

#include "Credentials.hpp"
#include <unordered_map>
#include <memory>

using namespace std;

class PasswordManager {
private:
    unique_ptr<unordered_map<string, vector<Credentials>>> services;
    
public:
    PasswordManager();
    ~PasswordManager();
    vector<Credentials> getCredentials(string service);
    void setCredentials(string service, Credentials credentials);
};

// PasswordManager::PasswordManager()

// :services(make_unique<unordered_map<string, Credentials>>()) {}

// PasswordManager::~PasswordManager() {

// }

// Credentials PasswordManager:: getCredentials(string service) {
    
// }

#endif