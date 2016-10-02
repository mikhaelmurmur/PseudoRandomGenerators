#pragma once
#include "IGeneratorBase.h"
#include <deque>
#include "LinearShiftRegister.h"
class CGeffeGenerator :
    public IGeneratorBase
{
public:
    explicit CGeffeGenerator(const lint& seed = lint(1));
    virtual ~CGeffeGenerator()=default;
    lint GetRandom()override;
    
private:
    static const std::deque<int> m_L9Coefs;
    static const std::deque<int> m_L10Coefs;
    static const std::deque<int> m_L11Coefs;
    std::deque<int> m_registerState;
    void GenerateStates(const lint& number);
    std::deque<int> ParseDequeFromLint(lint number, int numberOfDigits);
    CLinearShiftRegister m_L9, m_L10, m_L11;

};

