#ifndef MANUALSPLITSTRAEGY_HPP
#define MANUALSPLITSTRAEGY_HPP

#include "Expense.HPP"
#include "SplitStrategy.HPP"

class ManualSplitStrategy: public SplitStrategy
{
    public:
        virtual vector<int> determineSplit( int payeeCount , int totalAmount, vector<int> splitParams = vector<int>() );
};

#endif