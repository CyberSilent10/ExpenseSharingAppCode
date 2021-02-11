#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include "commonDefines.HPP"
#include "User.HPP"
#include "Expense.HPP"

class UserManager
{
    UserManager();

    public:
        unordered_map<string, User*> userStore;
        static UserManager *getInstance();
        bool registerUser(UserData *userData);
        User* getUser( string phoneNumber );
};

#endif