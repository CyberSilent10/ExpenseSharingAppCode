#include "commonDefines.HPP"
#include "User.HPP"
#include "Expense.HPP"
#include "SplitStrategy.HPP"
#include "SplitStrategyManager.HPP"
#include "UserManager.HPP"
#include "ExpenseManager.HPP"

ExpenseManager* ExpenseManager::getInstance()
{
    static ExpenseManager *instance = NULL;
    if ( instance == NULL )
    {
        instance = new ExpenseManager();
    }
    return instance;
}

bool ExpenseManager::createExpense( UserData *payer, int splitStratType, vector<UserData*> payeeList, int amount, vector<int> _splitParams, string _description )
{
    if ( payer == NULL || payeeList.size() == 0 ||  amount < 0 )
    {
        cout<<"Error: Invalid input params"<<endl;
        return false;
    }

    User *uPayer = UserManager::getInstance()->getUser( payer->phoneNumber );
    if ( uPayer == NULL )
    {
        cout<<"Error: Payer with phone number: " + payer->phoneNumber + " is not registered"<<endl;
    }

    vector<User*> uPayeeList;
    for(UserData *uPayeeData: payeeList)
    {
        User *uPayee = UserManager::getInstance()->getUser( uPayeeData->phoneNumber );
        if ( uPayee == NULL )
        {
            cout<<"Error: Payee with phone number: " + payer->phoneNumber + " is not registered!"<<endl;
            return false;
        }
        uPayeeList.push_back(uPayee);
    }

    SplitStrategy *splitStrat = SplitStrategyManager::getInstance()->getSplitStrategy( splitStratType );
    if ( splitStrat == NULL ) 
    {
        cout<<"Error: Invalid Split Strategy Type: " + splitStratType <<endl;
        return false;
    }
    Expense *expense = new Expense( uPayer, splitStrat, uPayeeList, amount, _splitParams, _description);
    if ( !expense->calculateSplit() )
    {
        return false;
    }
    expenseStore[payer->phoneNumber] = expense;
    return true;
}

void ExpenseManager::showBalanceForUser( string phoneNumber )
{
    Expense *expense = expenseStore[phoneNumber];
    User *uPayer = UserManager::getInstance()->getUser( phoneNumber );
    if ( uPayer == NULL || expense == NULL )
    {
        cout<<"Error: Cannot find user with phone number: " + phoneNumber<<endl;
        return;
    }
    cout<<"============================================================="<<endl;
    cout<<"Expense for user: " + uPayer->name<<endl;
    cout<<"Total Amount: " + expense->getTotalAmount()<<endl;
    cout<<"Description: " + expense->description<<endl;
    cout<<"Date: " + expense->createdDate + " Time: " + expense->createdTime<<endl;
    cout<<"Below list of people who owe " + uPayer->name<<endl;
    int i = 1;
    unordered_map<string, Share*>::iterator it = expense->shareMap.begin();
    for( ;it != expense->shareMap.end(); it++ )
    {
        cout<<i++<<"."<<endl;
        Share *s = it->second;
        User *uPayee = UserManager::getInstance()->getUser( it->first );
        cout<<"Name: " + uPayee->name + " Phone Number: " + uPayee->phoneNumber<<endl;
        cout<<"Amount: " + it->second->shareAmount<<endl;
        cout<<"Status: " + it->second->status;
        cout<<endl;
    }
    cout<<"============================================================="<<endl;
}