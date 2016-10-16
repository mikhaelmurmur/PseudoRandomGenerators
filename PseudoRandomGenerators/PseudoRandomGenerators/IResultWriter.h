#pragma once
#include <string>
#include "ITestBase.h"

class IResultWriter
{
public:
    explicit IResultWriter(const std::string& filename):m_filename(filename){}
    virtual ~IResultWriter()=default;
    virtual void WriteResults(TestResult result) = 0;
    const std::string& GetFileName()const { return m_filename; }
private:
    std::string m_filename;
};

