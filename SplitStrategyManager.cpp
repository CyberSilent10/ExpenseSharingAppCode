#include "SplitStrategy.HPP"
#include "EqualSplitStrategy.HPP"
#include "ManualSplitStrategy.HPP"
#include "PercentageSplitStrategy.HPP"
#include "SplitStrategyManager.HPP"

SplitStrategyManager::SplitStrategyManager()
{
    splitStrategyStore[SplitStrategyType::EQUAL] = new EqualSplitStrategy;
    splitStrategyStore[SplitStrategyType::PERCENTAGE] = new PercentageSplitStrategy();
    splitStrategyStore[SplitStrategyType::MANUAL] = new ManualSplitStrategy();
}

SplitStrategyManager* SplitStrategyManager::getInstance()
{
    static SplitStrategyManager *instance = NULL;
    if ( instance == NULL )
    {
        instance = new SplitStrategyManager();
    }
    return instance;
}

SplitStrategy* SplitStrategyManager::getSplitStrategy( int splitStratType )
{
    return splitStrategyStore[splitStratType];
}