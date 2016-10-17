#include "stdafx.h"
#include "XLSResultWriter.h"

namespace
{
    const wchar_t* GetWCharFromSting(const std::string& source)
    {
        return std::wstring(source.begin(),
            source.end()).c_str();
    }
}

void CXLSResultWriter::AddSheet(std::string sheetName)
{
    while(m_currentSheet==nullptr)
    {
        m_currentSheet = m_excelBook->addSheet(GetWCharFromSting(sheetName));
    }
    m_currentColumn = 0;
}

void CXLSResultWriter::WriteResults(TestResult result)
{
    m_currentSheet->writeNum(1, m_currentColumn, result.m_length);
    m_currentSheet->writeStr(2, m_currentColumn, GetWCharFromSting(result.m_testName));
    for(int alphaIndex=0;alphaIndex<3;++alphaIndex)
    {
        m_currentSheet->writeNum(3, m_currentColumn, result.m_results[alphaIndex].m_alpha);
        m_currentSheet->writeNum(4, m_currentColumn, result.m_results[alphaIndex].m_KhiCryteriaPractical);
        m_currentSheet->writeNum(5, m_currentColumn, result.m_results[alphaIndex].m_KhiCryteriaTheory);
        m_currentSheet->writeStr(6, m_currentColumn, result.m_results[alphaIndex].m_isAcceptable ? L"true" : L"false");
    }
    ++m_currentColumn;
}

void CXLSResultWriter::SaveResult()
{
    m_excelBook->save(L"tmp.xls");//GetWCharFromSting(GetFileName()));
    m_excelBook->release();
}
