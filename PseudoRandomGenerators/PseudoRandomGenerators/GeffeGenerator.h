#pragma once
#include "IGeneratorBase.h"
#include <deque>
#include "LinearShiftRegister.h"
class CGeffeGenerator :
    public IGeneratorBase
{
public:
    explicit CGeffeGenerator(const lint& seed = lint(1049601));
    virtual ~CGeffeGenerator()=default;
    lint GetRandom()override;
    EGeneratorType GetGeneratorType()const override { return BitGenerator; }
    const char * GetName() const override { return "Geffe Generator"; }
private:
    static const std::deque<int> m_L9Coefs;//TODO: naming. m_ prefix for members only. 
    static const std::deque<int> m_L10Coefs;
    static const std::deque<int> m_L11Coefs;
    std::deque<int> m_registerState;
    void GenerateStates(const lint& number);
    CLinearShiftRegister m_L9, m_L10, m_L11;

};

