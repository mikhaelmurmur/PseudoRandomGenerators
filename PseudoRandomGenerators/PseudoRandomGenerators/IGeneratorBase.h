#pragma once
#include <NTL/ZZ.h> 

typedef NTL::ZZ lint;

class IGeneratorBase
{
public:
    explicit IGeneratorBase(lint seed = lint(0))
        :m_seed(seed){}
    virtual ~IGeneratorBase() = default;
    virtual lint GetRandom() = 0;
protected:
    lint m_seed;
};
