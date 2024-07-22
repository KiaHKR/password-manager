#pragma once
#include "Credentials.hpp"
#include <string>
#include <unordered_map>
#include <iomanip>
#include <memory>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctype.h>

Credentials inputCredentials(std::string service);
std::string getServiceName();
void updateCredentialsSubMenu(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string serviceName, int choice); // what to modify
void handleCredentialsUpdate(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string serviceName);
void handleCredentialsDeletion(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string serviceName);
void updateLogin(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string serviceName, int choice);
void updatePassword(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string serviceName, int choice);