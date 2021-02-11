#ifndef SPLITSTRATEGY_HPP
#define SPLITSTRATEGY_HPP

#include <vector>
using namespace std;

class SplitStrategy
{
    public:
        virtual vector<int> determineSplit( int payeeCount , int totalAmount, vector<int> splitParams = vector<int>() ) = 0;
};

#endif