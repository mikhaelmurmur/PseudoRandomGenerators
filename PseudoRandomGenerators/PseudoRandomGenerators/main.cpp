// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BBSGenerator.h"
#include <iostream>
#include <memory>

int main()
{
    int k = 10000;
    std::shared_ptr<IGeneratorBase> generator = std::make_shared<CBBSGenerator>();
    while (k-->0)
    {
        std::cout << k << ' ' << generator->GetRandom() << std::endl;
    }

    return 0;
}

