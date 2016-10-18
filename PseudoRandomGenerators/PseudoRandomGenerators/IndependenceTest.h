#pragma once
#include "ITestBase.h"
#include "ZZHelper.h"

class CIndependenceTest :
    public ITestBase
{
public:
    explicit CIndependenceTest(const std::string& filename) :ITestBase(filename) { SetTestName("Independence test"); }
    explicit CIndependenceTest(const std::shared_ptr<IGeneratorBase> generator):ITestBase(generator){}
    virtual ~CIndependenceTest()=default;
    void FillResult(int length, TestResult& result,const std::vector<int>& values
        , const std::vector<int>& firstValues,const std::vector<int>& secondValues) const;
    TestResult ExecuteTesting(int length) override;
private:
    static double GetKhiCryteriaTheoretical(int length, ZZHelper::EQuantileValue quantile);
    static double GetKhiCryteriaPractical(const std::vector<int>& values, const std::vector<int>& firstValues,
        const std::vector<int>& secondValues, int length);
};

