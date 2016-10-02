#pragma once
#include <deque>
#include <string>

class CLinearShiftRegister
{
public:
    CLinearShiftRegister()=default;
    virtual ~CLinearShiftRegister()=default;
    int GetNextBit();
    void SetState(const std::deque<int>& state) { m_registerState = state; };
    void SetCoefs(const std::deque<int>& coefs) { m_registerCoefs = coefs; };
        
private:
    std::deque<int> m_registerState;
    std::deque<int> m_registerCoefs;

    
};

