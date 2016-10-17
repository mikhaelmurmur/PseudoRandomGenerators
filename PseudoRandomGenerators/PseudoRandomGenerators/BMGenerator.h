#pragma once
#include "IGeneratorBase.h"
class CBMGenerator :
    public IGeneratorBase
{
public:
    explicit CBMGenerator(const lint& seed = lint(1)) {}
    virtual ~CBMGenerator() = default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return BitGenerator; }
    const char * GetName() const override { return "BM Generator"; }
private:
    static const lint ms_primaryModulo;
    static const lint ms_primitiveRoot;
};

