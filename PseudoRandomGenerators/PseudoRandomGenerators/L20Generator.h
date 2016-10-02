#pragma once
#include "IGeneratorBase.h"
#include <deque>
#include "LinearShiftRegister.h"

class CL20_Generator :
    public IGeneratorBase
{
public:
    CL20_Generator(const lint& seed = lint(1));
    virtual ~CL20_Generator() = default;
    lint GetRandom()override;
private:
    static const std::deque<int> ms_L20Coefs;
    CLinearShiftRegister m_L20;
    void GenerateStates(const lint& number);
};

