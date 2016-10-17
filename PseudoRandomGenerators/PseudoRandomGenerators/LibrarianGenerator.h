#pragma once
#include "IGeneratorBase.h"
#include <fstream>

class CLibrarianGenerator :
    public IGeneratorBase
{
public:
    explicit CLibrarianGenerator(const lint& seed = lint(0));
    virtual ~CLibrarianGenerator()=default;
    lint GetRandom()override;
    void SetSeed(const lint& seed)override;
    const char * GetName() const override { return "Librarian Generator"; }
    EGeneratorType GetGeneratorType()const override { return ByteGenerator; }
private:
    static const std::string RANDOM_SOURCE_FILE_NAME;
    std::fstream m_randomSource;
    std::string m_currentLine;
    std::string::iterator m_currentCharacter;
    void SetTextStart(const lint& startPosition);
};

