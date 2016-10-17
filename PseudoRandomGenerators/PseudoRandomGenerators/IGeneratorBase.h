#pragma once
#include <NTL/ZZ.h> 

typedef NTL::ZZ lint;

enum EGeneratorType
{
    BitGenerator,
    ByteGenerator
};

class IGeneratorBase
{
public:
    explicit IGeneratorBase(const lint& seed = lint(0))
        :m_seed(seed){}
    virtual ~IGeneratorBase() = default;
    virtual lint GetRandom() = 0;
    virtual void SetSeed(const lint& seed);
    virtual const char * GetName() const
    { return "NoNameGenerator"; }
    virtual EGeneratorType GetGeneratorType()const { return BitGenerator; }
protected:
    lint m_seed;
};

inline void IGeneratorBase::SetSeed(const lint& seed)
{
    m_seed = seed;
}