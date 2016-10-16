#pragma once
#include <string>
#include <memory>
#include "IGeneratorBase.h"
#include <vector>

class IGeneratorBase;

struct AlphaTestResult
{
    float m_alpha;
    bool m_isAcceptable;
    double m_KhiCryteriaTheory;
    double m_KhiCryteriaPractical;
};

struct TestResult
{
    std::string m_generatorName;
    std::string m_testName;
    unsigned int m_length;
    AlphaTestResult m_results[3];
};

enum EQuantileValue
{
    weak,//0.1
    medium,//0.05
    strong//0.01
};

class ITestBase
{
public:
    enum TestMode
    {
        FileSourceMode,
        GeneratorMode
    };

    explicit ITestBase(const std::string& filename):m_testMode(FileSourceMode),m_filename(filename){}
    explicit ITestBase(const std::shared_ptr<IGeneratorBase>& generator)
        :m_testMode(GeneratorMode),m_generator(generator){}
    virtual ~ITestBase()=default;
    virtual TestResult ExecuteTesting(int length)=0;
    void SetTestName(const std::string& name) { m_testName = name; }

    const std::string& GetTestName() const{ return m_testName; }
protected:
    lint GetNextValue();
    const std::string& GetGeneratorName()const { return m_generator->GetName(); }
    static double GetKhiCryteriaTheoretical(int length, EQuantileValue quantile);
    static double GetKhiCryteriaPractical(const std::vector<int>& values);
private:
    TestMode m_testMode;
    std::string m_testName;
    std::shared_ptr<IGeneratorBase> m_generator;
    std::string m_filename;
};
