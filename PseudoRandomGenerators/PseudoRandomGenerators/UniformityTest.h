#pragma once
#include "ITestBase.h"
#include "ZZHelper.h"

class СUniformityTest :
    public ITestBase
{
public:
    explicit СUniformityTest(const std::string& filename) :ITestBase(filename) { SetTestName("Uniformity test"); }
    explicit СUniformityTest(const std::shared_ptr<IGeneratorBase>& generator)
        :ITestBase(generator) {}
    virtual ~СUniformityTest() = default;
    TestResult ExecuteTesting(int length) override;

private:
    static const int SEGMENTS_COUNT;
    void FillResults(int length, 
        TestResult& result, const std::vector<int>& bytesCountTotal
        , std::vector<std::vector<int>> bytesPerSegment, int segmentsCount)const;
    static double GetKhiCryteriaTheoretical(int length, ZZHelper::EQuantileValue quantile);
    static double GetKhiCryteriaPractical(const std::vector<int>& values, 
        const std::vector<std::vector<int>>& segmentValues, int length);
};

