#include "stdafx.h"
#include "ZZHelper.h"

namespace ZZHelper
{
    lint LintFromHex(char value)
    {
        auto result = lint(0);

        if ((-1 < value - '0')&&(value - '0' < 10))
        {
            result = lint(static_cast<int>(value - '0'));
            return result;
        }

        value = tolower(value);

        if ((-1<value - 'a')&&(value - 'a'<6))
        {
            result = lint(static_cast<int>(value - 'a')+10);
            return result;
        }
        return result;
    }

    lint LintFromHex(const std::string& hexValue)
    {
        lint result = lint(0);
        for(auto& digit : hexValue)
        {
            result += LintFromHex(digit);
            result <<= 4;
        }
        result >>= 4;
        return result;
    }
    
    lint Merge3ValuesOfLint(const lint& value9, const lint& value10, const lint& value11) 
    {
        return value9 + (value10 << 9) + (value11 << 19);
    }

    lint CycleBitShift(lint number,char letter) 
    {
        if (letter == 'r')
        {
            lint firstDigit = number & 1;

        }
        return lint(0);
    }

    std::deque<int> ParseDequeFromLint(lint number, int numberOfDigits)
    {
        std::deque<int> resultDeque;
        for (int i = 0; i < numberOfDigits; ++i)
        {
            resultDeque.push_back((number%NTL_MAX_INT) & 1);
            number >>= 1;
        }
        return resultDeque;
    }

    float GetQuantileValue(EQuantileValue quantile)
    {
        switch (quantile)
        {
        case weak:
            return 2.326f;

        case medium:
            return  2.56f;

        case strong:
            return 3.175f;
        }
        return 0.f;
    }
}
