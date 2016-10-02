// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneratorCreator.h"
#include <iostream>


int main()
{
    CGeneratorCreator generatorCreator;
    int k = 10000;
    auto generator = generatorCreator.CreateGenerator(CGeneratorCreator::BBS);
    while (k-->0)
    {
        std::cout << k << ' ' << generator->GetRandom() << std::endl;
    }

    return 0;
}

