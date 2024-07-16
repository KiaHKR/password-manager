#pragma once
#ifndef PASSWORD_H_
#define PASSWORD_H_
#include <string>
using namespace std;
// 8+ char
// 1 upper case, numbers, symbols
// no name, product, organization
class Password
{
private:
    string platform;
    string username;
    string email;
    string password;
public:
    Password(/* args */);
    ~Password();
};

Password::Password(/* args */)
{
}

Password::~Password() {

}


#endif