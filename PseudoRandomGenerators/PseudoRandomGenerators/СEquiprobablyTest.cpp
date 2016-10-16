#include "stdafx.h"
#include "СEquiprobablyTest.h"
#include <vector>

TestResult СEquiprobablyTest::ExecuteTesting(int length)
{
    TestResult result;
    std::vector<int> bytesCount(256);
    for(int byteNumber=0;byteNumber<length;++byteNumber)
    {
        auto randomValue = GetNextValue()%256;
        ++bytesCount[randomValue];
    }

    

    return result;
}

