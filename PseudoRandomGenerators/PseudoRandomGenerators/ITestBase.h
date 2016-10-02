#pragma once
#include <string>
#include <memory>

class IGeneratorBase;

class ITestBase
{
public:
    enum TestMode
    {
        FileSourceMode,
        GeneratorMode
    };

    explicit ITestBase(TestMode mode):m_testMode(mode){};
    explicit ITestBase(const std::string& filename):m_testMode(FileSourceMode),m_filename(filename){};
    explicit ITestBase(const std::shared_ptr<IGeneratorBase>& generator)
        :m_testMode(GeneratorMode),m_generator(generator){};
    virtual ~ITestBase()=default;
    virtual void ExecuteTesting()=0;
    void SetSourceFileName(const std::string& filename) { m_filename = filename; };
    void SetGenerator(const std::shared_ptr<IGeneratorBase>& generator) { m_generator = generator; };
    void SetTestName(const std::string& name) { m_testName = name; };

    const std::string& GetTestName() const{ return m_testName; };
    void SetTestMode(TestMode mode) { m_testMode = mode; };
private:
    TestMode m_testMode;
    std::string m_testName;
    std::shared_ptr<IGeneratorBase> m_generator;
    std::string m_filename;
};

