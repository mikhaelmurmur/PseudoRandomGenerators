#include "stdafx.h"
#include "EquiprobablyTest.h"
#include <vector>
#include "ZZHelper.h"

void CEquiprobablyTest::FillResults(int length, TestResult& result,const std::vector<int>& bytesCount)const
{//bullshit
    result.m_testName = GetTestName();
    result.m_generatorName = GetGeneratorName();

    result.m_length = length;

    result.m_results[0].m_KhiCryteriaPractical = 
        result.m_results[1].m_KhiCryteriaPractical = 
        result.m_results[2].m_KhiCryteriaPractical = 
        GetKhiCryteriaPractical(bytesCount,length);

    result.m_results[0].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(length, ZZHelper::weak);
    result.m_results[0].m_isAcceptable = result.m_results[0].m_KhiCryteriaPractical 
        < result.m_results[0].m_KhiCryteriaTheory;
    result.m_results[0].m_alpha = 0.1f;


    result.m_results[1].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(length, ZZHelper::medium);
    result.m_results[1].m_isAcceptable = result.m_results[1].m_KhiCryteriaPractical
        < result.m_results[1].m_KhiCryteriaTheory;
    result.m_results[1].m_alpha = 0.05f;


    result.m_results[2].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(length, ZZHelper::strong);
    result.m_results[2].m_isAcceptable = result.m_results[2].m_KhiCryteriaPractical
        < result.m_results[2].m_KhiCryteriaTheory;
    result.m_results[2].m_alpha = 0.01f;
}

TestResult CEquiprobablyTest::ExecuteTesting(int length)
{
    TestResult result;
    std::vector<int> bytesCount(256);
    for(int byteNumber=0;byteNumber<length;++byteNumber)
    {
        auto randomValue = GetNextValue()%256;
        ++bytesCount[randomValue];
    }
    FillResults(length, result, bytesCount);

    return result;
}


double CEquiprobablyTest::GetKhiCryteriaTheoretical(int length, ZZHelper::EQuantileValue quantile)
{
    return (sqrt(255 * 2)*GetQuantileValue(quantile) + 255);
}

double CEquiprobablyTest::GetKhiCryteriaPractical(const std::vector<int>& values, int length)
{
    double result = 0;
    const double mediana = length / 256.;
    for (auto& value : values)
    {
        result += (value - mediana) * (value - mediana) / (mediana);
    }
    return result;
}