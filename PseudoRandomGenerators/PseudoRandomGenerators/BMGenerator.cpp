#include "stdafx.h"
#include "BMGenerator.h"
#include "ZZHelper.h"
#include <string>

const lint CBMGenerator::PRIMARY_MODULO = 
            ZZHelper::LintFromHex("CEA42B987C44FA642D80AD9F51F10457690DEF10C83D0BC1BCEE12FC3B6093E3");
const lint CBMGenerator::PRIMITIVE_ROOT = 
            ZZHelper::LintFromHex("5B88C41246790891C095E2878880342E88C79974303BD0400B090FE38A688356");


CBMGenerator::CBMGenerator(const lint & seed)
    :IGeneratorBase(seed)
{
}

lint CBMGenerator::GetRandom()
{
    m_seed = NTL::PowerMod(PRIMITIVE_ROOT, m_seed, PRIMARY_MODULO);
    
    if (m_seed < ((PRIMARY_MODULO - 1) / 2))
        return lint(1); 
    else
        return lint(0);
}


//This file is a total fucking hack