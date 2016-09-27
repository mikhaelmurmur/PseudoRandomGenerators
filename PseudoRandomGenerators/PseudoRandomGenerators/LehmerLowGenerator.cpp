#include "stdafx.h"
#include "LehmerLowGenerator.h"


CLehmerLowGenerator::CLehmerLowGenerator(const lint& seed)
{
    m_generator.SetSeed(seed);
}

lint CLehmerLowGenerator::GetRandom()
{
    auto lehmerValue = m_generator.GetRandom();
    auto result = lint(0);
    for (int degree = 0; degree <8; ++degree)
    {
        result += (lehmerValue) & (1<<degree);
    }
    return result;
}
