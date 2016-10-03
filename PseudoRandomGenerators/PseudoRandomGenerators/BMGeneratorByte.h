#pragma once
#include "IGeneratorBase.h"
class CBMGeneratorByte :
    public IGeneratorBase
{
public:
    CBMGeneratorByte(const lint& seed = lint(1)) {};
    virtual ~CBMGeneratorByte() = default;
    lint GetRandom()override;
private:
    static const lint ms_primaryModulo;
    static const lint ms_primitiveRoot;
};

