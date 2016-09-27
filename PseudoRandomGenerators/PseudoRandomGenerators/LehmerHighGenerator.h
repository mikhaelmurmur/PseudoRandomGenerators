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
private:
    CLehmerGeneratorGeneral m_generator;
};

