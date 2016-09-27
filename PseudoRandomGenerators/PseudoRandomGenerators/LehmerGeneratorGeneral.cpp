#include "stdafx.h"
#include "LehmerGeneratorGeneral.h"



const lint CLehmerGeneratorGeneral::MODULO=NTL::power(lint(2),32);
const lint CLehmerGeneratorGeneral::MULT_COEF=NTL::power(lint(2),16)+1;
const lint CLehmerGeneratorGeneral::ADD_COEF = lint(119);

CLehmerGeneratorGeneral::CLehmerGeneratorGeneral(const lint& seed)
{
    m_seed = seed;
}

lint CLehmerGeneratorGeneral::GetRandom()
{
    m_seed = (MULT_COEF*m_seed + ADD_COEF) % MODULO;
    return m_seed;
}
