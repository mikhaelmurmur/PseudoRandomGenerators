#include "stdafx.h"
#include "LehmerHighGenerator.h"

CLehmerHighGenerator::CLehmerHighGenerator(const lint& seed)
{
    m_seed = seed;
    m_generator.SetSeed(m_seed);
}

lint CLehmerHighGenerator::GetRandom()
{
    auto lehmerValue = m_generator.GetRandom();
    auto result = lint(0);
    for (int degree = 0; degree < 8; ++degree)
    {
        result <<= 1;
        result |= (lehmerValue >> (31-degree))& 1;
    }
    return result;
}
