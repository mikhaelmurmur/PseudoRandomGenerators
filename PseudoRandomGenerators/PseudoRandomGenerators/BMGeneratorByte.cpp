#include "stdafx.h"
#include "BMGeneratorByte.h"

#include "ZZHelper.h"

const lint CBMGeneratorByte::ms_primaryModulo = 
                    ZZHelper::LintFromHex("CEA42B987C44FA642D80AD9F51F10457690DEF10C83D0BC1BCEE12FC3B6093E3");
const lint CBMGeneratorByte::ms_primitiveRoot = 
                    ZZHelper::LintFromHex("5B88C41246790891C095E2878880342E88C79974303BD0400B090FE38A688356");


lint CBMGeneratorByte::GetRandom()
{
    m_seed = NTL::PowerMod(ms_primitiveRoot, m_seed, ms_primaryModulo);
    for (int k = 0; k < 256; ++k)//TODO: fucking naming 
    {
        if ((m_seed > (k*(ms_primaryModulo - 1) / 256))
            && (m_seed >= ((k + 1)*(ms_primaryModulo - 1) / 256)))
        {
            return lint(k);
        }
    }
    return lint(-1);
}

