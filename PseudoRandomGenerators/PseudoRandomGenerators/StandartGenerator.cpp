#include "stdafx.h"
#include "StandartGenerator.h"


CStandartGenerator::CStandartGenerator(const lint& seed)
{
    m_seed = seed;
    srand(m_seed%NTL_MAX_INT);
}

lint CStandartGenerator::GetRandom()
{
    return lint(rand() % 2);
}
