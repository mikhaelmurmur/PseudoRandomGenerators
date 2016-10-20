#include "stdafx.h"
#include "LinearShiftRegister.h"



int CLinearShiftRegister::GetNextBit()
{
    int nextBit = 0;
    for(auto& coef: m_registerCoefs)
    {
        nextBit += m_registerState[coef];
    }
    int result = m_registerState.front();
    m_registerState.pop_front();
    m_registerState.push_back(nextBit % 2);
    return result ;
}