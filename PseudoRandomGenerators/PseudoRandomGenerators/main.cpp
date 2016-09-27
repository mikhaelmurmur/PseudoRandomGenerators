// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LehmerLowGenerator.h"
#include "LehmerGeneratorGeneral.h"
#include <iostream>
#include <memory>

int main()
{
    int k = 10;
    std::shared_ptr<IGeneratorBase> generator = std::make_shared<CLehmerLowGenerator>();
    std::shared_ptr<IGeneratorBase> generatorGeneral = std::make_shared<CLehmerGeneratorGeneral>();
    while (k-->0)
    {
        std::cout << k << ' ' << generator->GetRandom() << std::endl;
        std::cout << k << ' ' << generatorGeneral->GetRandom() << std::endl;
    }

    return 0;
}

