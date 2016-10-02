#pragma once
#include "IGeneratorBase.h"
#include <memory>
class CGeneratorCreator
{
public:
    CGeneratorCreator() = default;
    ~CGeneratorCreator() = default;
    
    enum GeneratorType
    {
        Standart,
        LehmarHigh,
        LehmarLow,
        Librarian,
        BBS,
        BBSByte,
        Count
    };

    std::shared_ptr<IGeneratorBase> CreateGenerator(GeneratorType generatorType,lint seed = lint(0))const;
};

