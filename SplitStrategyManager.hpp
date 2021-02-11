#ifndef SPLITSTRATEGYMANAGER_HPP
#define SPLITSTRATEGYMANAGER_HPP

#include "SplitStrategy.HPP"

class SplitStrategyManager
{
    SplitStrategyManager();

    public:
        unordered_map<int, SplitStrategy*> splitStrategyStore;
        static SplitStrategyManager *getInstance();
        SplitStrategy* getSplitStrategy( int splitStratType );
};

#endif