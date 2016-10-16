#include "stdafx.h"
#include "СEquiprobablyTest.h"
#include <vector>

void СEquiprobablyTest::FillResults(int length, TestResult& result,const std::vector<int>& bytesCount)const
{
    result.m_testName = GetTestName();
    result.m_generatorName = GetGeneratorName();

    result.m_length = length;

    result.m_results[0].m_KhiCryteriaPractical = 
        result.m_results[1].m_KhiCryteriaPractical = 
        result.m_results[2].m_KhiCryteriaPractical = 
        GetKhiCryteriaPractical(bytesCount);




    result.m_results[0].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(length, weak);
    result.m_results[0].m_isAcceptable = result.m_results[0].m_KhiCryteriaPractical 
        < result.m_results[0].m_KhiCryteriaTheory;
    result.m_results[0].m_alpha = 0.1f;


    result.m_results[1].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(length, medium);
    result.m_results[1].m_isAcceptable = result.m_results[1].m_KhiCryteriaPractical
        < result.m_results[1].m_KhiCryteriaTheory;
    result.m_results[1].m_alpha = 0.05f;


    result.m_results[2].m_KhiCryteriaTheory = GetKhiCryteriaTheoretical(length, strong);
    result.m_results[2].m_isAcceptable = result.m_results[2].m_KhiCryteriaPractical
        < result.m_results[2].m_KhiCryteriaTheory;
    result.m_results[2].m_alpha = 0.01f;
}

TestResult СEquiprobablyTest::ExecuteTesting(int length)
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

