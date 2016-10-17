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
    auto l10bit = m_L10.GetNextBit();
    return static_cast<lint>(m_L11.GetNextBit()&l10bit) ^ ((1 ^ l10bit)&m_L9.GetNextBit());
}

void CGeffeGenerator::GenerateStates(const lint& number)
{
    m_L9.SetCoefs(m_L9Coefs);
    m_L10.SetCoefs(m_L9Coefs);
    m_L11.SetCoefs(m_L9Coefs);
    lint a = number&(511);//(1<<8 - 1) //TODO:: FUCKING NAMING, BITCH
    lint b = number&(524287 - 511);
    lint c = number&(1073741823 - 524287);
    m_L9.SetState(ZZHelper::ParseDequeFromLint(a, 9));
    m_L10.SetState(ZZHelper::ParseDequeFromLint(b, 10));
    m_L11.SetState(ZZHelper::ParseDequeFromLint(c, 11));
}