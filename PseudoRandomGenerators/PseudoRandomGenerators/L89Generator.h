#pragma once
#include "IGeneratorBase.h"
#include<deque>
#include"LinearShiftRegister.h"
class CL89Generator :
    public IGeneratorBase
{
public:
    CL89Generator(const lint& seed = lint(1));
    virtual ~CL89Generator() = default;
    lint GetRandom()override;
private:
    static const std::deque<int> ms_L89Coefs;
    CLinearShiftRegister m_L89;
    void GenerateStates(const lint& number);
};

