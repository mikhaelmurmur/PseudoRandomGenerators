#include "stdafx.h"
#include "ITestBase.h"
#include "IGeneratorBase.h"

namespace
{
    float GetQuantileValue(EQuantileValue quantile)
    {
        switch (quantile)
        {
        case weak:
            return 2.326f;

        case medium:
            return  2.56f;

        case strong:
            return 3.175f;
        }
        return 0.f;
    }
}

lint ITestBase::GetNextValue()
{
    if(m_generator->GetGeneratorType()==BitGenerator)
    {
        lint result(m_generator->GetRandom());
        for(int i=1;i<8;++i)
        {
            result <<= 1;
            result += m_generator->GetRandom();
        }
        return result;
    }
    else
    {
        return m_generator->GetRandom();
    }
}

double ITestBase::GetKhiCryteriaTheoretical(int length, EQuantileValue quantile)
{
    return (sqrt(length * 2)*GetQuantileValue(quantile) + length);
}

double ITestBase::GetKhiCryteriaPractical(const std::vector<int>& values)
{
    double result = 0;
    const double mediana = values.size() / 256.;
    for(auto& value: values)
    {
        result += (value + mediana) * (value + mediana) / (mediana);
    }
    return result;
}
