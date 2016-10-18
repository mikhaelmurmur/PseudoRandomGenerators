#pragma once
#include "ITestBase.h"
#include "ZZHelper.h"

class CEquiprobablyTest :
    public ITestBase
{
public:
    explicit CEquiprobablyTest(const std::string& filename):ITestBase(filename) { SetTestName("Equiprobability test"); }
    explicit CEquiprobablyTest(const std::shared_ptr<IGeneratorBase>& generator)
        :ITestBase(generator){}
    virtual ~CEquiprobablyTest() = default;
    TestResult ExecuteTesting(int length) override;

private:
    void FillResults(int length, TestResult& result,const std::vector<int>& bytesCount)const;
    static double GetKhiCryteriaTheoretical(int length, ZZHelper::EQuantileValue quantile);
    static double GetKhiCryteriaPractical(const std::vector<int>& values, int length);
};
