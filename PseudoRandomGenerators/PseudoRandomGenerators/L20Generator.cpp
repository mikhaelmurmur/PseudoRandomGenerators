#include "stdafx.h"
#include "L20Generator.h"


 const std::deque<int> CL20_Generator::ms_L20Coefs = { 0,11,15,17 };

CL20_Generator::CL20_Generator(const lint& seed)
{
    m_seed = seed;
    GenerateStates(seed);
}

lint CL20_Generator::GetRandom()
{
    return static_cast<lint>(m_L20.GetNextBit());
}

void CL20_Generator::GenerateStates(const lint& number)
{
    m_L20.SetCoefs(ms_L20Coefs);
    // the same
    lint a = number&(1048576);
    m_L20.SetState(ms_L20Coefs);  // лажа
}