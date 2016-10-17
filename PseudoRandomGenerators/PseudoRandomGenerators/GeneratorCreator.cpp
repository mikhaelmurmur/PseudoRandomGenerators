#include "stdafx.h"
#include "GeneratorCreator.h"
#include "StandartGenerator.h"
#include "BBSGenerator.h"
#include "BBSGeneratorByte.h"
#include "LehmerHighGenerator.h"
#include "LehmerLowGenerator.h"
#include "LibrarianGenerator.h"
#include "BMGenerator.h"
#include "BMGeneratorByte.h"
#include "WolframGenerator.h"
#include "GeffeGenerator.h"
#include "L20Generator.h"
#include "L89Generator.h"


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
    case BM:
        return std::make_shared<CBMGenerator>(seed);
    case BMByte:
        return std::make_shared<CBMGeneratorByte>(seed);
    case Geffe:
        return std::make_shared<CGeffeGenerator>();
    case Wolfram:
        return std::make_shared<CWolframGenerator>(seed);
    case L20:
        return std::make_shared<CL20Generator>(seed);
    case L89:
        return std::make_shared<CL89Generator>(seed);
    default:
        return std::make_shared<CStandartGenerator>(seed);
    }
}


