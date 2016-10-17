#pragma once
#include "IGeneratorBase.h"
class CBMGeneratorByte :
    public IGeneratorBase
{
public:
    explicit CBMGeneratorByte(const lint& seed = lint(1)) {}
    virtual ~CBMGeneratorByte() = default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return ByteGenerator; }
    const char * GetName() const override { return "BM Byte Generator"; }
private:
    static const lint ms_primaryModulo; //TODO:: fix naming. ms_ prefix for static members, but not for static constants
    static const lint ms_primitiveRoot;
};

