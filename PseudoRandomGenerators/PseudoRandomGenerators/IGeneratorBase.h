#pragma once
#include <NTL/ZZ.h> 

typedef NTL::ZZ lint;

class IGeneratorBase
{
public:
    explicit IGeneratorBase(const lint& seed = lint(0))
        :m_seed(seed){}
    virtual ~IGeneratorBase() = default;
    virtual lint GetRandom() = 0;
    virtual void SetSeed(const lint& seed);
protected:
    lint m_seed;
};

inline void IGeneratorBase::SetSeed(const lint& seed)
{
    m_seed = seed;
}
