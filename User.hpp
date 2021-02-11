#ifndef USER_HPP
#define USER_HPP

#include <string>
using namespace std;

class User
{
    public:
        string emailId;
        string phoneNumber;
        string name;
        User( string _emailId, string _phoneNumber, string _name );
};

#endif