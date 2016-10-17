#include "stdafx.h"
#include "UniformityTest.h"

const int СUniformityTest::SEGMENTS_COUNT = 20;

namespace
{
    struct SPair
    {
        int m_segmentNumber;
        std::vector<int> m_byteCount;
        explicit SPair(int segmentNumber)
            :m_segmentNumber(segmentNumber),m_byteCount(256)
        {}
    };
}

TestResult СUniformityTest::ExecuteTesting(int length)
{
    TestResult result;
    std::vector<std::vector<int>> values(SEGMENTS_COUNT);
    std::vector<int> totalValue(256);
    auto segmentSize = length / SEGMENTS_COUNT;
    for (int segmentIndex = 0; segmentIndex<SEGMENTS_COUNT; ++segmentIndex)
    {
        values[segmentIndex].resize(256);
        for(int byteIndex = 0;byteIndex < segmentSize;++byteIndex)
        {
            auto randomValue = GetNextValue() % 256;
            ++values[segmentIndex][randomValue];
            ++totalValue[randomValue];
        }
    }
    FillResults(length, result, totalValue, values,SEGMENTS_COUNT);

    return result;
}


void СUniformityTest::FillResults(int length, TestResult& result, const std::vector<int>& bytesCountTotal, 
    std::vector<std::vector<int>> bytesPerSegment, int segmentsCount) const
{//bullshit
    result.m_testName = GetTestName();
    result.m_generatorName = GetGeneratorName();

    result.m_length = length;

    result.m_results[0].m_KhiCryteriaPractical =
        result.m_results[1].m_KhiCryteriaPractical =
        result.m_results[2].m_KhiCryteriaPractical =
        GetKhiCryteriaPractical(bytesCountTotal, bytesPerSegment,length/segmentsCount);

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

double СUniformityTest::GetKhiCryteriaTheoretical(int length, ZZHelper::EQuantileValue quantile)
{
    return (sqrt(255*2*(SEGMENTS_COUNT-1))*GetQuantileValue(quantile) + 255*(SEGMENTS_COUNT-1));
}

double СUniformityTest::GetKhiCryteriaPractical(const std::vector<int>& values,const std::vector<std::vector<int>>& segmentValues, int segmentSize)
{
    double result = 0;
    for (int byteIndex = 0;byteIndex<256;++byteIndex)
    {
        for(auto& segmentInfo: segmentValues)
        {
            if(values[byteIndex]==0)
            {
                continue;
            }
            result += static_cast<double>(segmentInfo[byteIndex] * segmentInfo[byteIndex])/ segmentSize / values[byteIndex];
        }
    }
    return (result-1)*segmentSize*SEGMENTS_COUNT;
}
