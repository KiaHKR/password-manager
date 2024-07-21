#ifndef HELPERFUNCTIONS_HPP_
#define HELPERFUNCTIONS_HPP_
#include "Credentials.hpp"
#include <string>
#include <unordered_map>
#include <iomanip>
#include <memory>
#include <vector>

Credentials inputCredentials(std::string service);
void updateCredentialsSubMenu();
void updatePassword(std::string *service);
void updateLogin(std::string *service);
std::string inputLogin();
std::string inputPassword();
void handleCredentialsUpdate(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string *serviceName);
#endif