#include "ManualSplitStrategy.HPP"
#include <vector>
#include <numeric> 

vector<int> ManualSplitStrategy::determineSplit( int payeeCount , int totalAmount, vector<int> splitParams )
{
    if ( payeeCount == 0 || totalAmount <= 0 )
    {
        cout<<"Error: Invalid Input, unable to decide split"<<endl;
        return vector<int>();
    }

    int totalPayeeAmount = accumulate( splitParams.begin(), splitParams.end(), 0 );
    if ( totalAmount != totalPayeeAmount )
    {
        cout<<"Error: Improper Split Amounts, unable to decide split"<<endl;
        return vector<int>();
    }

    return splitParams;
}