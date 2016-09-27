#pragma once
#include "IGeneratorBase.h"
class CLehmerGeneratorGeneral :
    public IGeneratorBase
{
public:
    explicit CLehmerGeneratorGeneral(lint seed =lint(0));
    virtual ~CLehmerGeneratorGeneral()=default;
private:
    static const lint MODULO;
    
};

