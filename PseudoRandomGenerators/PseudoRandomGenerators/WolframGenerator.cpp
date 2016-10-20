#include "stdafx.h"
#include "WolframGenerator.h"
#include "ZZHelper.h"


lint CWolframGenerator::GetRandom() 
{
    lint result = m_seed % (lint(2));
    m_seed = ZZHelper::CycleBitShift(m_seed,true) ^ (m_seed | ZZHelper::CycleBitShift(m_seed, false)); 
    return result;
}
