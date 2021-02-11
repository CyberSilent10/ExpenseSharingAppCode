#ifndef EXPENSEMANAGER_HPP
#define EXPENSEMANAGER_HPP

#include "commonDefines.HPP"
#include "Expense.HPP"
#include "SplitStrategy.HPP"

class ExpenseManager
{
    ExpenseManager();

    public:
        unordered_map<string, Expense*> expenseStore;
        static ExpenseManager *getInstance();
        bool createExpense( UserData *payer, int splitStratType, vector<UserData*> payeeList, int amount, vector<int> _splitParams = vector<int>(), string _description = "" );
        void showBalanceForUser( string phoneNumber );
};

#endif