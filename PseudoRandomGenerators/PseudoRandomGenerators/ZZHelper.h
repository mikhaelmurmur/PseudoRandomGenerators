#pragma once
#include <NTL/ZZ.h>

typedef NTL::ZZ lint;

namespace ZZHelper
{
    lint LintFromHex(char value);
    lint LintFromHex(const std::string& hexValue);
}