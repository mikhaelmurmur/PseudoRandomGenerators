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

    lint CycleBitShift(const lint& number,bool isLeftShift) 
    {
        lint result(1);
        long nullState2Digit = ((result.rep).rep)[3];
        long firstDigit, secondDigit;
        if (((number.rep).rep)[0] == 2)
        {
            firstDigit = ((number.rep).rep)[1];
            secondDigit = ((number.rep).rep)[2];
        }
        else
        {
            firstDigit = ((number.rep).rep)[1];
            secondDigit = 0;
        }
        if (isLeftShift)
        {
            if (((firstDigit & (1 << 30)) >> 30) == 0)
                ((result.rep).rep)[2] = nullState2Digit;
            else
                ((result.rep).rep)[2] = (firstDigit & (1 << 30)) >> 30;
            ((result.rep).rep)[1] = (firstDigit << 1) + secondDigit;
            if (((result.rep).rep)[2] == nullState2Digit)
                ((result.rep).rep)[0] = 1;
            else
                ((result.rep).rep)[0] = 2;
        }
        else
        {
            if ( (firstDigit & 1) == 0)
                ((result.rep).rep)[2] = nullState2Digit;
            else
                ((result.rep).rep)[2] = (firstDigit & 1);
            ((result.rep).rep)[1] = ((secondDigit << 30) + (firstDigit >> 1));
            if (((result.rep).rep)[2] == nullState2Digit)
                ((result.rep).rep)[0] = 1;
            else
                ((result.rep).rep)[0] = 2;
        }
        return result;
    }
    

    std::deque<int> ParseDequeFromLint(lint number, int numberOfDigits)    ///
    {
        std::deque<int> resultDeque;
        if (numberOfDigits == 10)
            number >>= 9;
        if (numberOfDigits == 11)
            number >>= 19;
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
            return 4.61f;

        case medium:
            return  5.99f;

        case strong:
            return 9.21f;
        }
        return 0.f;
    }
}
