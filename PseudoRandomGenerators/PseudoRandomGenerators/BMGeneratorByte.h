#pragma once
#include "IGeneratorBase.h"
class CBMGeneratorByte :
    public IGeneratorBase
{
public:
    explicit CBMGeneratorByte(const lint& seed = lint(1)):IGeneratorBase(seed) {}
    virtual ~CBMGeneratorByte() = default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return ByteGenerator; }
    const char * GetName() const override { return "BM Byte Generator"; }
private:
    static const lint PRIMARY_MODULO; 
    static const lint PRIMITIVE_ROOT;
};

