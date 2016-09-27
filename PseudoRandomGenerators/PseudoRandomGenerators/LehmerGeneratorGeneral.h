#pragma once
#include "IGeneratorBase.h"
class CLehmerGeneratorGeneral :
    public IGeneratorBase
{
public:
    explicit CLehmerGeneratorGeneral(const lint& seed =lint(1));
    virtual ~CLehmerGeneratorGeneral()=default;
    lint GetRandom()override;
private:
    static const lint MODULO;
    static const lint MULT_COEF;
    static const lint ADD_COEF;
};

