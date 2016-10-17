#pragma once
#include "IGeneratorBase.h"
#include "LehmerGeneratorGeneral.h"
class CLehmerHighGenerator :
    public IGeneratorBase
{
public:
    explicit CLehmerHighGenerator(const lint& seed = lint(1));
    virtual ~CLehmerHighGenerator()=default;
    lint GetRandom() override;
    const char * GetName() const override { return "Lehmar High Generator"; }
    EGeneratorType GetGeneratorType()const override { return ByteGenerator; }
private:
    CLehmerGeneratorGeneral m_generator;
};

