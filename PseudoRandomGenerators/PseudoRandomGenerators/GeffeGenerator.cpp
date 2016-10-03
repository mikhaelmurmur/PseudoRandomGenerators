#include "stdafx.h"
#include "GeffeGenerator.h"
#include "LinearShiftRegister.h"
#include "ZZHelper.h"

const std::deque<int> CGeffeGenerator::m_L9Coefs = { 0,1,3,4 };
const std::deque<int> CGeffeGenerator::m_L10Coefs = { 0,3 };
const std::deque<int> CGeffeGenerator::m_L11Coefs = { 0,2 };



CGeffeGenerator::CGeffeGenerator(const lint& seed)
{
    m_seed = seed;
    GenerateStates(seed);
}



lint CGeffeGenerator::GetRandom()
{
    return static_cast<lint>(m_L11.GetNextBit()&m_L10.GetNextBit()) ^ ((1 ^ m_L10.GetNextBit())&m_L9.GetNextBit());
}

void CGeffeGenerator::GenerateStates(const lint& number)
{
    // generation of states, not correct at the moment
    m_L9.SetCoefs(m_L9Coefs);
    m_L10.SetCoefs(m_L9Coefs);
    m_L11.SetCoefs(m_L9Coefs);
    // i tried to generate 3 states from input number. Dont ask why)
    lint a = number&(511);//(1<<8 - 1)
    lint b = number&(524287 - 511);
    lint c = number&(1073741823 - 524287);
    m_L9.SetState(ZZHelper::ParseDequeFromLint(a, 9));
    m_L10.SetState(ZZHelper::ParseDequeFromLint(b, 10));
    m_L11.SetState(ZZHelper::ParseDequeFromLint(c, 11));
}