#pragma once
#include "IGeneratorBase.h"
class CStandartGenerator :
    public IGeneratorBase
{
public:
    explicit CStandartGenerator(NTL::ZZ seed = NTL::ZZ(0));
    virtual ~CStandartGenerator()=default;
    NTL::ZZ GetRandom()override;
};

