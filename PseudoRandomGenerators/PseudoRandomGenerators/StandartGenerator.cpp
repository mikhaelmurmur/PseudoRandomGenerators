#include "stdafx.h"
#include "StandartGenerator.h"


CStandartGenerator::CStandartGenerator(NTL::ZZ seed)
{
    m_seed = seed;
    srand(m_seed%NTL_MAX_INT);
}

NTL::ZZ CStandartGenerator::GetRandom()
{
    return NTL::ZZ(rand() % 2);
}
