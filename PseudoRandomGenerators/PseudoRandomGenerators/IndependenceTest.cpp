#include "stdafx.h"
#include "IndependenceTest.h"

void CIndependenceTest::FillResult(int length, TestResult& result, const std::vector<int>& values, 
    const std::vector<int>& firstValues, const std::vector<int>& secondValues) const
{
    result.m_testName = L"Independence Test";//GetTestName();
    result.m_generatorName = GetGeneratorName();

    result.m_length = length;

    result.m_results[0].m_KhiCryteriaPractical =
        result.m_results[1].m_KhiCryteriaPractical =
        result.m_results[2].m_KhiCryteriaPractical =
        GetKhiCryteriaPractical(values,firstValues,secondValues, length);

    result.m_results[0].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(255, ZZHelper::weak);
    result.m_results[0].m_isAcceptable = result.m_results[0].m_KhiCryteriaPractical
        < result.m_results[0].m_KhiCryteriaTheory;
    result.m_results[0].m_alpha = 0.1f;


    result.m_results[1].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(255, ZZHelper::medium);
    result.m_results[1].m_isAcceptable = result.m_results[1].m_KhiCryteriaPractical
        < result.m_results[1].m_KhiCryteriaTheory;
    result.m_results[1].m_alpha = 0.05f;


    result.m_results[2].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(255, ZZHelper::strong);
    result.m_results[2].m_isAcceptable = result.m_results[2].m_KhiCryteriaPractical
        < result.m_results[2].m_KhiCryteriaTheory;
    result.m_results[2].m_alpha = 0.01f;
}

TestResult CIndependenceTest::ExecuteTesting(int length)
{
    TestResult result;
    std::vector<int> values(256 * 256);
    std::vector<int> firstValues(256);
    std::vector<int> secondValues(256);
    for(int i=0;i<length/2;++i)
    {
        auto firstValue = GetNextValue()%256;
        auto secondValue = GetNextValue()%256;
        ++values[firstValue * 256 + secondValue];
        ++firstValues[firstValue];
        ++secondValues[secondValue];
    }

    FillResult(length, result, values, firstValues, secondValues);

    return result;
}

double CIndependenceTest::GetKhiCryteriaTheoretical(int length, ZZHelper::EQuantileValue quantile)
{
    return sqrt(2)*length*ZZHelper::GetQuantileValue(quantile) + length*length;
}

double CIndependenceTest::GetKhiCryteriaPractical(const std::vector<int>& values, const std::vector<int>& firstValues,
                                                    const std::vector<int>& secondValues, int length)
{
    double result=0;
    for(int firstByte = 0;firstByte<256;++firstByte)
    {
        for(int secondByte = 0;secondByte<256;++secondByte)
        {
            if((secondValues[secondByte]==0)||(firstValues[firstByte]==0))
            {
                continue;
            }
            result += (values[256 * firstByte + secondByte])*
                static_cast<double>((values[256 * firstByte + secondByte]))
                / (secondValues[secondByte]*
                    firstValues[firstByte]);
        }
    }
    return (result-1.)*length/2;
}
