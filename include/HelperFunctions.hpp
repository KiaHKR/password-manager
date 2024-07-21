#ifndef HELPERFUNCTIONS_HPP_
#define HELPERFUNCTIONS_HPP_
#include "Credentials.hpp"
#include <string>
#include <unordered_map>
#include <iomanip>
#include <memory>
#include <vector>
#include <iostream>
#include <cstdio>

Credentials inputCredentials(std::string* service);
std::string getServiceName();
void updateCredentialsSubMenu(); //what to modify
void handleCredentialsUpdate(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string* serviceName);
#endif