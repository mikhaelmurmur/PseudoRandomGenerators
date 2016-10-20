#include "stdafx.h"
#include "L20Generator.h"
#include "ZZHelper.h"

 const std::deque<int> CL20Generator::L20COEFS = { 0,11,15,17 };

CL20Generator::CL20Generator(const lint& seed)
{
    m_seed = seed;
    GenerateStates(seed);
}

lint CL20Generator::GetRandom()
{
    return lint(m_L20.GetNextBit()); //TODO: maybe better to construct a tmp var
}

void CL20Generator::GenerateStates(const lint& number)
{
    m_L20.SetCoefs(L20COEFS);
    // the same
    lint L20StateValue = number&(1048575); 
    m_L20.SetState(ZZHelper::ParseDequeFromLint(L20StateValue, 20));
}
