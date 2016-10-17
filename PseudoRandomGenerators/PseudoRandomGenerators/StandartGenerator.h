#pragma once
#include "IGeneratorBase.h"
class CStandartGenerator :
    public IGeneratorBase
{
public:
    explicit CStandartGenerator(const lint& seed = lint(0));
    virtual ~CStandartGenerator()=default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return ByteGenerator; }
    const char * GetName() const override { return "Standart Generator"; }
};

