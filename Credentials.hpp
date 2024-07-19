#pragma once
#ifndef CREDENTIALS_H_
#define CREDENTIALS_H_
#include <string>
using namespace std;
// 8+ char
// 1 upper case, numbers, symbols
// no name, product, organization
struct Credentials
{
    string login;
    string password;
};
#endif