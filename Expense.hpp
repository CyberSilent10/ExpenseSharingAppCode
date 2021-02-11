#ifndef EXPENSE_H
#define EXPENSE_H

#include "commonDefines.HPP"
#include "User.HPP"
#include "SplitStrategy.HPP"

class Expense
{
    public:
        User *payer;
        SplitStrategy *splitStrat;
        unordered_map<string, Share*> shareMap;
        int totalAmount;
        string description;
        string createdDate;
        string createdTime;
        vector<int> splitParams;

        Expense( User *_payer, SplitStrategy *_splitStrat, vector<User*> payeeList, int _amount, vector<int> _splitParams = vector<int>(), string _description = "");
        bool calculateSplit();
        int getTotalAmount();
        int getPayeeCount();
};

#endif