#ifndef PERCENTAGESPLITSTRAEGY_HPP
#define PERCENTAGESPLITSTRAEGY_HPP

#include "Expense.HPP"
#include "SplitStrategy.HPP"

class PercentageSplitStrategy: public SplitStrategy
{
    public:
        virtual vector<int> determineSplit( int payeeCount , int totalAmount, vector<int> splitParams = vector<int>() );
};

#endif