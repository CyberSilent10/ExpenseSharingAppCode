#include "PercentageSplitStrategy.HPP"
#include <numeric> 
#include <vector>

vector<int> PercentageSplitStrategy::determineSplit( int payeeCount , int totalAmount, vector<int> splitParams )
{
    if ( payeeCount == 0 || totalAmount <= 0 || ( accumulate( splitParams.begin(), splitParams.end() , 0 ) != 100 ) )
    {
        cout<<"Error: Invalid Input, unable to decide split"<<endl;
        return vector<int>();
    }

    vector<int> ret;
    for( int i = 0; i < payeeCount; i++)
    {
        ret.push_back( totalAmount * ( splitParams[i]/100 ) );
    }
    return ret;
}