#include "stdafx.h"
#include "L89Generator.h"
#include "ZZHelper.h"

const std::deque<int> CL89Generator::L89COEFS = { 0,51 };


CL89Generator::CL89Generator(const lint& seed)
{
    m_seed = seed;
    GenerateStates(seed);
}

lint CL89Generator::GetRandom()
{
    return lint(m_L89.GetNextBit());
}

void CL89Generator::GenerateStates(const lint& number)
{
    m_L89.SetCoefs(L89COEFS);
    lint L89StateValue = number & (((lint)(1<<88))-1);
    m_L89.SetState(ZZHelper::ParseDequeFromLint(L89StateValue, 89));
}

