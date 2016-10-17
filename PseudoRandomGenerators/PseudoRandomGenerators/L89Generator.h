#pragma once
#include "IGeneratorBase.h"
#include<deque>
#include"LinearShiftRegister.h"
class CL89Generator :
    public IGeneratorBase
{
public:
    explicit CL89Generator(const lint& seed = lint(1));
    virtual ~CL89Generator() = default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return BitGenerator; }
    const char * GetName() const override { return "L89 Generator"; }
private:
    static const std::deque<int> ms_L89Coefs; //TODO: fucking naming
    CLinearShiftRegister m_L89;
    void GenerateStates(const lint& number);
};

