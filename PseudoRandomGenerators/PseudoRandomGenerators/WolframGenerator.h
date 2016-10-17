#pragma once
#include "IGeneratorBase.h"
class CWolframGenerator :
    public IGeneratorBase
{
public:
    explicit CWolframGenerator(const lint& seed = lint(1)) {}
    virtual ~CWolframGenerator() = default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return BitGenerator; }
    const char * GetName() const override { return "Wolfram Generator"; }

};

