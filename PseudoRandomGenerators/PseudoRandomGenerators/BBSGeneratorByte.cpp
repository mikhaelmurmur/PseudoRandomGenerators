#include "stdafx.h"
#include "ZZHelper.h"
#include "BBSGeneratorByte.h"

const lint CBBSGeneratorByte::FIRST_FACTOR = ZZHelper::LintFromHex("D5BBB96D30086EC484EBA3D7F9CAEB07");
const lint CBBSGeneratorByte::SECOND_FACTOR = ZZHelper::LintFromHex("425D2B9BFDB25B9CF6C416CC6E37B59C1F");
const lint CBBSGeneratorByte::MODULO = FIRST_FACTOR * SECOND_FACTOR;

CBBSGeneratorByte::CBBSGeneratorByte(const lint& seed)
{
    m_seed = seed;
}

lint CBBSGeneratorByte::GetRandom()
{
    m_seed = (m_seed*m_seed) % MODULO;
    return lint(m_seed % 256);
}
