#pragma once
#include <NTL/ZZ.h> 

class IGeneratorBase
{
public:
    explicit IGeneratorBase(NTL::ZZ seed = NTL::ZZ(0))
        :m_seed(seed){}
    virtual ~IGeneratorBase() = default;
    virtual NTL::ZZ GetRandom() = 0;
protected:
    NTL::ZZ m_seed;
};
