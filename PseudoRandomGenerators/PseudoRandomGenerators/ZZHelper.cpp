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
    
}
