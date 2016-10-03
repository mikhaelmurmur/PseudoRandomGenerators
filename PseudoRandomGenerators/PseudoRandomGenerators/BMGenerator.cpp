#include "stdafx.h"
#include "BMGenerator.h"
#include "ZZHelper.h"
#include <string>

const lint CBMGenerator::ms_primaryModulo = 
            ZZHelper::LintFromHex("CEA42B987C44FA642D80AD9F51F10457690DEF10C83D0BC1BCEE12FC3B6093E3");
const lint CBMGenerator::ms_primitiveRoot = 
            ZZHelper::LintFromHex("5B88C41246790891C095E2878880342E88C79974303BD0400B090FE38A688356");


lint CBMGenerator::GetRandom()
{
    m_seed = NTL::PowerMod(ms_primitiveRoot, m_seed,ms_primaryModulo);
    if (m_seed < ((ms_primaryModulo - 1) / 2))
        return lint(1);
    else
        return lint(0);
}
