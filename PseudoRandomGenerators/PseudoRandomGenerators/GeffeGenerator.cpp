#include "stdafx.h"
#include "GeffeGenerator.h"
#include "LinearShiftRegister.h"
#include "ZZHelper.h"

const std::deque<int> CGeffeGenerator::L9COEFS = { 0,1,3,4 };
const std::deque<int> CGeffeGenerator::L10COEFS = { 0,3 };
const std::deque<int> CGeffeGenerator::L11COEFS = { 0,2 };



CGeffeGenerator::CGeffeGenerator(const lint& seed)
{
    m_seed = seed;
    GenerateStates(seed);
}



lint CGeffeGenerator::GetRandom()
{
    auto l10bit = m_L10.GetNextBit();
    return lint(m_L11.GetNextBit() & l10bit) ^ ((1 ^ l10bit) & m_L9.GetNextBit());
}

void CGeffeGenerator::GenerateStates(const lint& number)
{
    m_L9.SetCoefs(L9COEFS);
    m_L10.SetCoefs(L10COEFS);
    m_L11.SetCoefs(L11COEFS);
    lint L9StateValue = number & (511);  //(1<<8 - 1) 
    lint L10StateValue = number & (524287 - 511);
    lint L11StateValue = number & (1073741823 - 524287);
    m_L9.SetState(ZZHelper::ParseDequeFromLint(L9StateValue, 9));
    m_L10.SetState(ZZHelper::ParseDequeFromLint(L10StateValue, 10));
    m_L11.SetState(ZZHelper::ParseDequeFromLint(L11StateValue, 11));
}