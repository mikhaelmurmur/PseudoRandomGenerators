#include "stdafx.h"
#include "WolframGenerator.h"


lint CWolframGenerator::GetRandom() 
{
    lint result = m_seed%(lint(2));
    m_seed = (m_seed << 1) ^ (m_seed | (m_seed >> 1)); //TODO: Andrii mustfix  //no cycle shift, but standart
    return result;
}
