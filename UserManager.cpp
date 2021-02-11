#include "commonDefines.HPP"
#include "User.HPP"
#include "Expense.HPP"
#include "UserManager.HPP"

UserManager* UserManager::getInstance()
{
    static UserManager *instance = NULL;
    if ( instance == NULL )
    {
        instance = new UserManager();
    }
    return instance;
}

bool UserManager::registerUser(UserData *userData)
{
    if ( userStore[userData->phoneNumber] != NULL )
    {
        cout<<"Error: User with phone number '" + userData->phoneNumber + "' already exists"<<endl;
        return false;
    }

    if ( userData->phoneNumber.size() != 10 )
    {
        cout<<"Error: Invalid phone number " + userData->phoneNumber<<endl;
        return false;
    }

    User *newUser = new User( userData->emailId, userData->phoneNumber, userData->name );
    userStore[userData->phoneNumber] = newUser;
    return true;
}

User* UserManager::getUser( string phoneNumber )
{
    if ( userStore[phoneNumber] == NULL )
    {
        cout<<"Error: User with phone number '" + phoneNumber + "' not registered!"<<endl;
        return NULL;
    }
    
    return userStore[phoneNumber];
}