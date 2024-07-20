#ifndef HELPERFUNCTIONS_HPP_
#define HELPERFUNCTIONS_HPP_
#pragma once
#include "Credentials.hpp"
#include <string>
#include <unordered_map>
#include <iomanip>

Credentials inputCredentials(string service);
void updateCredentialsSubMenu();
void updatePassword(string *service);
void updateLogin(string *service);
string inputLogin();
string inputPassword();
void handleCredentialsUpdate(unordered_map<string, vector<Credentials>>* services);

#endif