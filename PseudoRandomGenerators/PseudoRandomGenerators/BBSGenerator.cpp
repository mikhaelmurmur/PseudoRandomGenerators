#include "stdafx.h"
#include "BBSGenerator.h"
#include "ZZHelper.h"

const lint CBBSGenerator::FIRST_FACTOR = ZZHelper::LintFromHex("D5BBB96D30086EC484EBA3D7F9CAEB07");
const lint CBBSGenerator::SECOND_FACTOR = ZZHelper::LintFromHex("425D2B9BFDB25B9CF6C416CC6E37B59C1F");
const lint CBBSGenerator::MODULO = FIRST_FACTOR * SECOND_FACTOR;


CBBSGenerator::CBBSGenerator(const lint& seed)
{
    m_seed = seed;
}

lint CBBSGenerator::GetRandom()
{
    m_seed = (m_seed*m_seed) % MODULO;
    long tmp = m_seed % 2;
    return lint(tmp);
}
