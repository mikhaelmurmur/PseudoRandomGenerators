#include "stdafx.h"
#include "GeneratorCreator.h"
#include "StandartGenerator.h"
#include "BBSGenerator.h"
#include "BBSGeneratorByte.h"
#include "LehmerHighGenerator.h"
#include "LehmerLowGenerator.h"
#include "LibrarianGenerator.h"

std::shared_ptr<IGeneratorBase> CGeneratorCreator::CreateGenerator(GeneratorType generatorType, lint seed) const
{
    switch (generatorType)
    {
    case Standart:
        return std::make_shared<CStandartGenerator>(seed);
    case BBS:
        return std::make_shared<CBBSGenerator>(seed);
    case BBSByte:
        return std::make_shared<CBBSGeneratorByte>(seed);
    case LehmarHigh:
        return std::make_shared<CLehmerHighGenerator>(seed);
    case LehmarLow:
        return std::make_shared<CLehmerLowGenerator>(seed);
    case Librarian:
        return std::make_shared<CLibrarianGenerator>(seed);
    default:
        return std::make_shared<CStandartGenerator>(seed);
    }
}


