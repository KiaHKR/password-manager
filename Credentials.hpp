#pragma once
#ifndef CREDENTIALS_H_
#define CREDENTIALS_H_
#include <string>
// 8+ char
// 1 upper case, numbers, symbols
// no name, product, organization
struct Credentials
{
    std::string login;
    std::string password;
};
#endif