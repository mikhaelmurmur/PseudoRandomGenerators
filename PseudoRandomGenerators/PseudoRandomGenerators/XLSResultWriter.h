#pragma once
#include "IResultWriter.h"
#include "libxl.h"

class CXLSResultWriter :
    public IResultWriter
{
public:
    explicit CXLSResultWriter(const std::string& filename) :IResultWriter(filename)
        , m_excelBook(xlCreateBook())
        , m_currentSheet(nullptr)
        , m_currentColumn(0){}
    virtual ~CXLSResultWriter() = default;
    
    void AddSheet(std::string sheetName);
    void WriteResults(TestResult result) override;
    void SaveResult();
private:
    libxl::Book* m_excelBook;
    libxl::Sheet* m_currentSheet;
    int m_currentColumn;
};

