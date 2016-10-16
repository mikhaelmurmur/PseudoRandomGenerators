#pragma once
#include "ITestBase.h"
#include "ZZHelper.h"

class СEquiprobablyTest :
    public ITestBase
{
public:
    explicit СEquiprobablyTest(const std::string& filename):ITestBase(filename) {}
    explicit СEquiprobablyTest(const std::shared_ptr<IGeneratorBase>& generator)
        :ITestBase(generator){}
    virtual ~СEquiprobablyTest() = default;
    TestResult ExecuteTesting(int length) override;

private:
    void FillResults(int length, TestResult& result,const std::vector<int>& bytesCount)const;
    static double GetKhiCryteriaTheoretical(int length, ZZHelper::EQuantileValue quantile);
    static double GetKhiCryteriaPractical(const std::vector<int>& values, int length);
};
