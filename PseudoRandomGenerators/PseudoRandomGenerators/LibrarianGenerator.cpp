#include "stdafx.h"
#include "LibrarianGenerator.h"

const std::string CLibrarianGenerator::RANDOM_SOURCE_FILE_NAME = "text.txt";

CLibrarianGenerator::CLibrarianGenerator(const lint& seed)
    :m_randomSource(RANDOM_SOURCE_FILE_NAME)
{
    m_seed = seed;
    if (m_randomSource.is_open())
    {
        m_randomSource>>m_currentLine;
        m_currentCharacter = m_currentLine.begin();
    }
    else
    {//HACK
        int* i = nullptr;
        (*i);//If it crashes here, it means you don't have text.txt file
    }
}

lint CLibrarianGenerator::GetRandom()
{
    char resultCharacter = 0;
    
    if(m_currentCharacter==m_currentLine.end())
    {
        if(m_randomSource.eof())
        {
            m_randomSource.close();
            m_randomSource.open(RANDOM_SOURCE_FILE_NAME);
        }
        m_randomSource >> m_currentLine;
        m_currentCharacter = m_currentLine.begin();
    }

    resultCharacter = *m_currentCharacter;
    ++m_currentCharacter;
    auto result = lint(resultCharacter);
    result = result % 256;
    return result;
}

void CLibrarianGenerator::SetSeed(const lint& seed)
{
    m_seed = seed;
    m_randomSource.close();
    m_randomSource.open(RANDOM_SOURCE_FILE_NAME);
    SetTextStart(m_seed);
}

void CLibrarianGenerator::SetTextStart(const lint& startPosition)
{
    char tmp = 0;
    for (int position = 0; position < startPosition; ++position)
    {
        if (m_randomSource.eof())
        {
            m_randomSource.close();
            m_randomSource.open(RANDOM_SOURCE_FILE_NAME);
            continue;
        }
        m_randomSource >> tmp;
    }
}

