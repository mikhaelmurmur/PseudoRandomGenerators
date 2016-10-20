#pragma once
#include <NTL/ZZ.h>
#include <deque>
typedef NTL::ZZ lint;

namespace ZZHelper
{
    enum EQuantileValue
    {
        weak,//0.1
        medium,//0.05
        strong//0.01
    };
    lint LintFromHex(char value);
    lint LintFromHex(const std::string& hexValue);
    lint Merge3ValuesOfLint(const lint& value9, const lint& value10, const lint& value11 );//create seed for geffe
    lint CycleBitShift(const lint& number, bool isLeftShift);
    std::deque<int> ParseDequeFromLint(lint number, int numberOfDigits);
    float GetQuantileValue(EQuantileValue quantile);
}