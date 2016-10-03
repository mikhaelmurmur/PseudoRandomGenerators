#pragma once
#include "IGeneratorBase.h"
class CBMGenerator :
    public IGeneratorBase
{
public:
    CBMGenerator(const lint& seed = lint(1)) {};
    virtual ~CBMGenerator() = default;
    lint GetRandom()override;
private:
    static const lint ms_primaryModulo;
    static const lint ms_primitiveRoot;
};

