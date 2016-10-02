// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneratorCreator.h"
#include <iostream>
#include <memory>


int main()
{
    CGeneratorCreator generatorCreator;
    int k = 10000;
    std::shared_ptr<IGeneratorBase> generator = generatorCreator.CreateGenerator(CGeneratorCreator::BBS,lint(2));
    while (k-->0)
    {
        std::cout << k << ' ' << generator->GetRandom() << std::endl;
    }

    return 0;
}

