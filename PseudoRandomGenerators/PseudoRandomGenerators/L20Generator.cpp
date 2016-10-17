#include "stdafx.h"
#include "L20Generator.h"
#include "ZZHelper.h"

 const std::deque<int> CL20Generator::ms_L20Coefs = { 0,11,15,17 };

CL20Generator::CL20Generator(const lint& seed)
{
    m_seed = seed;
    GenerateStates(seed);
}

lint CL20Generator::GetRandom()
{
    return static_cast<lint>(m_L20.GetNextBit()); //TODO: maybe better to construct a tmp var
}

void CL20Generator::GenerateStates(const lint& number)
{
    m_L20.SetCoefs(ms_L20Coefs);
    // the same
    lint a = number&(1048576); //TODO:: what the fuck??? naming 
    m_L20.SetState(ZZHelper::ParseDequeFromLint(a, 20));
}
