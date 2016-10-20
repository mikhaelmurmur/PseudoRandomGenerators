#pragma once
#include "IGeneratorBase.h"
#include <deque>
#include "LinearShiftRegister.h"
class CGeffeGenerator :
    public IGeneratorBase
{
public:
    explicit CGeffeGenerator(const lint& seed = lint(524801)); // 2^0 + 2^9 + 2^19
    virtual ~CGeffeGenerator()=default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return BitGenerator; }
    const char * GetName() const override { return "Geffe Generator"; }
private:
    static const std::deque<int> L9COEFS; 
    static const std::deque<int> L10COEFS;
    static const std::deque<int> L11COEFS;
    std::deque<int> m_registerState;
    void GenerateStates(const lint& number);
    CLinearShiftRegister m_L9, m_L10, m_L11;

};

