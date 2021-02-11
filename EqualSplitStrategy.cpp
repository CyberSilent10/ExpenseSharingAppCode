#include "Expense.HPP"
#include "EqualSplitStrategy.HPP"

vector<int> EqualSplitStrategy::determineSplit( int payeeCount , int totalAmount, vector<int> splitParams )
{
    if ( payeeCount == 0 || totalAmount <= 0 || ( ( totalAmount % payeeCount ) != 0 ) )
    {
        cout<<"Error: Invalid Input, unable to decide split"<<endl;
        return vector<int>();
    }
    return vector<int>( payeeCount, totalAmount/payeeCount );
}