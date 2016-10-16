#include "stdafx.h"
#include "XLSResultWriter.h"
#include "libxl.h"

void CXLSResultWriter::WriteResults(TestResult result)
{
    auto resultBook = xlCreateBook();
    if (!resultBook)
    {
        return;
    }
    auto sheet = resultBook->addSheet(
        std::wstring(result.m_testName.begin(), 
            result.m_testName.end()).c_str());

    sheet->writeNum(1, 1, 10);
    resultBook->save(std::wstring(GetFileName().begin(),GetFileName().end()).c_str());
}
