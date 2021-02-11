#include "commonDefines.HPP"
#include "User.HPP"
#include "SplitStrategy.HPP"
#include "Expense.HPP"

Expense::Expense(User *_payer, SplitStrategy *_splitStrat, vector<User*> payeeList, int _amount, vector<int> _splitParams, string _description ) 
: payer(_payer),
  splitStrat(_splitStrat), 
  totalAmount(_amount),
  splitParams(_splitParams), 
  description(_description)
{
    for(User* u: payeeList)
    {
        shareMap[u->phoneNumber] = new Share();
    }
    createdDate = "10/02/2021";
    createdTime = "10:30:00";
}

bool Expense::calculateSplit()
{
    vector<int> splitAmounts( splitStrat->determineSplit( shareMap.size(), totalAmount, splitParams ) );
    if ( splitAmounts.empty() )
        return false;

    for ( int splitAmount : splitAmounts )
    {
        unordered_map<string,Share*>::iterator it = shareMap.begin();
        for( ; it != shareMap.end(); it++ )
        {
            it->second->shareAmount = splitAmount;
            it->second->status = PENDING;
        }
    }
    return true;
}

int Expense::getTotalAmount()
{
    return totalAmount;
}

int Expense::getPayeeCount()
{
    return shareMap.size();
}