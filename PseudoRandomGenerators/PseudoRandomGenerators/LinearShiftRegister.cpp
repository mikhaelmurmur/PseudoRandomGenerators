#include "stdafx.h"
#include "LinearShiftRegister.h"




int CLinearShiftRegister::GetNextBit()
{
    int nextBit = 0;
    //for (int i = 0; i < m_registerCoefs.size ; ++i)
    for(auto& coef: m_registerCoefs)
    {
        nextBit += m_registerState[coef];
    }
    int result = m_registerState.front();
    m_registerState.pop_front();
    m_registerState.push_front(nextBit);
    return result % 2;
    //прибрати в блоці
}