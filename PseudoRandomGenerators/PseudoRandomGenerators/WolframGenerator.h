#pragma once
#include "IGeneratorBase.h"
class CWolframGenerator :
    public IGeneratorBase
{
public:
    CWolframGenerator(const lint& seed = lint(1)) {};
    virtual ~CWolframGenerator() = default;
    lint GetRandom()override;


};

