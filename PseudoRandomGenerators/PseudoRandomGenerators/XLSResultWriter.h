#pragma once
#include "IResultWriter.h"

class CXLSResultWriter :
    public IResultWriter
{
public:
    explicit CXLSResultWriter(const std::string& filename):IResultWriter(filename){}
    virtual ~CXLSResultWriter() = default;
    void WriteResults(TestResult result) override;
};

