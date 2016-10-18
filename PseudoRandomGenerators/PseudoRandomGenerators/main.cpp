// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneratorCreator.h"
#include <iostream>
#include "TestCreator.h"
#include "XLSResultWriter.h"
#include "GeffeGenerator.h"

void CalculateStatistics()
{
    CGeneratorCreator generatorCreator;
    CTestCreator testCreator;
    CXLSResultWriter resultXLS("results.xls");
    for(int generatorIndex = 0;generatorIndex<CGeneratorCreator::Count-2;++generatorIndex)
    {
        auto generator = generatorCreator.CreateGenerator(static_cast<CGeneratorCreator::GeneratorType>(generatorIndex), lint(100));
        resultXLS.AddSheet(std::string(generator->GetName()));
        int size = 1000000;
        //for(int size = 1000;size<10000;size*=10)
        {
            for(int testIndex = 0;testIndex<CTestCreator::count;++testIndex)
            {
                auto test = testCreator.CreateTesting(static_cast<CTestCreator::ETestTypes>(testIndex), generator);
                auto result = test->ExecuteTesting(size);
                resultXLS.WriteResults(result);
            }
        }
    }
    resultXLS.SaveResult();
}

int main()
{
    CalculateStatistics();

    return 0;
}

