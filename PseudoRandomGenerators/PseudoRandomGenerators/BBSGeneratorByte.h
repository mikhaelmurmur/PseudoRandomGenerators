#pragma once
#include "IGeneratorBase.h"
class CBBSGeneratorByte :
    public IGeneratorBase
{
public:
    explicit CBBSGeneratorByte(const lint& seed = lint(2));
    virtual ~CBBSGeneratorByte() = default;
    lint GetRandom()override;
    const char * GetName() const override { return "BBS byte Generator"; }
    EGeneratorType GetGeneratorType()const override { return ByteGenerator; }
private:
    static const lint FIRST_FACTOR;
    static const lint SECOND_FACTOR;
    static const lint MODULO;
};

