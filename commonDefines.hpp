#ifndef COMMONDEFINES_H
#define COMMONDEFINES_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

enum SplitStrategyType
{
    MANUAL = 0,
    EQUAL  = 1,
    PERCENTAGE = 2
};

enum Status
{
    CREATED = 0,
    PENDING = 1,
    SETTLED = 2
};

struct UserData
{
    string name;
    string emailId;
    // This is our unique Id for each user
    string phoneNumber;
};

struct Share
{
    int shareAmount;
    Status status;
    Share(): shareAmount( 0 ), status( Status::CREATED )
    {
        
    }
};

#endif