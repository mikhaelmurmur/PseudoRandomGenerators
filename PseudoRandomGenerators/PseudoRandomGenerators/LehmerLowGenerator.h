#pragma once
#include "IGeneratorBase.h"
#include "LehmerGeneratorGeneral.h"
class CLehmerLowGenerator :
    public IGeneratorBase
{
public:
    explicit CLehmerLowGenerator(const lint& seed = lint(1));
    virtual ~CLehmerLowGenerator()=default;
    lint GetRandom()override;
private:
    CLehmerGeneratorGeneral m_generator;
};

