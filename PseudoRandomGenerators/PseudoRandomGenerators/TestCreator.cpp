#include "stdafx.h"
#include "TestCreator.h"
#include "UniformityTest.h"
#include "IndependenceTest.h"
#include "EquiprobablyTest.h"

std::unique_ptr<ITestBase> CTestCreator::CreateTesting(ETestTypes type, std::shared_ptr<IGeneratorBase>& generator)
{
    switch (type)
    {
    case Independence:
        return std::make_unique<CIndependenceTest>(generator);
    case Equiprobably:
        return std::make_unique<CEquiprobablyTest>(generator);
    case Uniformity:
        return std::make_unique<СUniformityTest>(generator);
    }
    return std::make_unique<CIndependenceTest>(generator);
}
