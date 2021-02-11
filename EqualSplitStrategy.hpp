#ifndef EQUALSPLITSTRATEGY_H
#define EQUALSPLITSTRATEGY_H

#include "Expense.HPP"
#include "SplitStrategy.HPP"

class EqualSplitStrategy: public SplitStrategy
{
    public:
        virtual vector<int> determineSplit( int payeeCount , int totalAmount, vector<int> splitParams = vector<int>() );
};

#endif