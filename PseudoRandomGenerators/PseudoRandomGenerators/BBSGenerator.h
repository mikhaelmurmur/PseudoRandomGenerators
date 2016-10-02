#pragma once
#include "IGeneratorBase.h"
class CBBSGenerator :
    public IGeneratorBase
{
public:
    explicit CBBSGenerator(const lint& seed = lint(2));
    virtual ~CBBSGenerator()=default;
    lint GetRandom()override;

private:
    static const lint FIRST_FACTOR;
    static const lint SECOND_FACTOR;
    static const lint MODULO;
};

