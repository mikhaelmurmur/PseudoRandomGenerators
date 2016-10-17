#include "stdafx.h"
#include "L89Generator.h"
#include "ZZHelper.h"

const std::deque<int> CL89Generator::ms_L89Coefs = { 0,51 };


CL89Generator::CL89Generator(const lint& seed)
{
    m_seed = seed;
    GenerateStates(seed);
}

lint CL89Generator::GetRandom()
{
    return static_cast<lint>(m_L89.GetNextBit());
}

void CL89Generator::GenerateStates(const lint& number)
{
    m_L89.SetCoefs(ms_L89Coefs);
    lint a = number&(((lint)(1<<89))-1); //TODO: you know what to do
    m_L89.SetState(ZZHelper::ParseDequeFromLint(a, 89));
}

