#pragma once
#include "IGeneratorBase.h"
#include <deque>
#include "LinearShiftRegister.h"

class CL20Generator :
    public IGeneratorBase
{
public:
    explicit CL20Generator(const lint& seed = lint(1));
    virtual ~CL20Generator() = default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return BitGenerator; }
    const char * GetName() const override { return "L20 Generator"; }
private:
    static const std::deque<int> L20COEFS; //TODO: lovely naming, soft server
    CLinearShiftRegister m_L20;
    void GenerateStates(const lint& number);
};

