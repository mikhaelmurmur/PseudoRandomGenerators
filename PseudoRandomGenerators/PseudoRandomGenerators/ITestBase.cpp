#include "stdafx.h"
#include "ITestBase.h"
#include "IGeneratorBase.h"

lint ITestBase::GetNextValue()
{
    if(m_generator->GetGeneratorType()==BitGenerator)
    {
        lint result(m_generator->GetRandom()%2);
        for(int i=1;i<8;++i)
        {
            result <<= 1;
            result |= m_generator->GetRandom()%2;
        }
        return result;
    }
    return m_generator->GetRandom();
}

