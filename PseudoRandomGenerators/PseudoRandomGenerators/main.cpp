// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LibrarianGenerator.h"
#include <iostream>
#include <memory>

int main()
{
    int k = 10;
    std::shared_ptr<IGeneratorBase> generator = std::make_shared<CLibrarianGenerator>();
    while (k-->0)
    {
        std::cout << k << ' ' << generator->GetRandom() << std::endl;
    }

    return 0;
}

