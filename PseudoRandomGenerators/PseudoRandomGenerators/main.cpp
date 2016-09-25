// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StandartGenerator.h"
#include <iostream>
#include <memory>

int main()
{
    int k = 10;
    std::shared_ptr<IGeneratorBase> generator = std::make_shared<CStandartGenerator>();
    while (k-->0)
    {
        std::cout <<k<<' '<< generator->GetRandom()<<std::endl;
    }

    return 0;
}

