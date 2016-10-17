#pragma once
#include <memory>
#include "ITestBase.h"



class CTestCreator
{
public:
    enum ETestTypes
    {
        Independence,
        Equiprobably,
        Uniformity,
        count
    };
    explicit CTestCreator()=default;
    ~CTestCreator()=default;
    std::unique_ptr<ITestBase> CreateTesting(ETestTypes type,std::shared_ptr<IGeneratorBase>& generator);
};

