#ifndef KeyParser_cpp
#define KeyParser_cpp
#include "KeyParser.h"
#include "../Exceptions/ExitGame.h"
#include <unordered_set>
#define NUMBER_OF_COMMANDS 5

KeyParser::KeyParser(const char *filename)
{
    file.open(filename, std::ios::in);
    std::string line;
    std::unordered_set<std::string> checkCommandsDuplicates;
    std::unordered_set<std::string> checkKeysDuplicates;
    int numberOfCommands = 0;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string token1, token2;
            std::getline(ss, token1, '=');
            std::getline(ss, token2);
            checkCommandsDuplicates.insert(token1);
            checkKeysDuplicates.insert(token2);
            if (key_commands::stringToCommand.find(token1) == key_commands::stringToCommand.end())
            {
                throw std::out_of_range("");
            }
            else
            {
                keyDict[token2[0]] = key_commands::stringToCommand.at(token1);
            }
            numberOfCommands++;
        }
    }
    file.close();
    if (checkCommandsDuplicates.size() != keyDict.size() || checkKeysDuplicates.size() != keyDict.size())
        throw std::invalid_argument("");
    if (numberOfCommands != NUMBER_OF_COMMANDS)
        throw ExitGame(1);
}

std::map<char, COMMAND> KeyParser::getKeyDict() const
{
    return this->keyDict;
}

KeyParser::~KeyParser()
{
    if (file.is_open())
    {
        file.close();
    }
}

#endif