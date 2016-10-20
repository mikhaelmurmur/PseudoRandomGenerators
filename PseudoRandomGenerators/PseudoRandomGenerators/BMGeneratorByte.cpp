#include "stdafx.h"
#include "BMGeneratorByte.h"

#include "ZZHelper.h"

const lint CBMGeneratorByte::PRIMARY_MODULO = 
                    ZZHelper::LintFromHex("CEA42B987C44FA642D80AD9F51F10457690DEF10C83D0BC1BCEE12FC3B6093E3");
const lint CBMGeneratorByte::PRIMITIVE_ROOT = 
                    ZZHelper::LintFromHex("5B88C41246790891C095E2878880342E88C79974303BD0400B090FE38A688356");


lint CBMGeneratorByte::GetRandom()
{
    m_seed = NTL::PowerMod(PRIMITIVE_ROOT, m_seed, PRIMARY_MODULO);
    for (int byteValue = 0; byteValue < 256; ++byteValue) 
    {
        if ((m_seed > (byteValue*(PRIMARY_MODULO - 1) / 256))
            && (m_seed >= ((byteValue + 1)*(PRIMARY_MODULO - 1) / 256)))
        {
            return lint(byteValue);
        }
    }
    return lint(-1);
}

