#include "customParser.h"

customParser::customParser(const std::string &htmlContent) : htmlStream(htmlContent) {}

customParser::~customParser()
{
    htmlStream.clear();
}

void customParser::findHeaders()
{
    while (reader.find("<div class=\"row\">") == std::string::npos)
    {
        std::getline(htmlStream, reader);
    }

    findBG();
    findFaction();
    findTimeAndDate();
}

void customParser::findBG()
{
    std::getline(htmlStream, reader);
    std::getline(htmlStream, reader);

    int bracketsFromBack = 2;
    int backIndex;
    for (backIndex = reader.length() - 1; bracketsFromBack; backIndex--)
        if (reader[backIndex] == '<')
            bracketsFromBack--;

    while (reader[backIndex] != '>')
    {
        battlegroundName = reader[backIndex] + battlegroundName;
        backIndex--;
    }
}

void customParser::findFaction()
{
    std::getline(htmlStream, reader);
    std::getline(htmlStream, reader);
    std::getline(htmlStream, reader);

    int bracketsFromBack = 2;
    int backIndex;
    for (backIndex = reader.length() - 1; bracketsFromBack; backIndex--)
        if (reader[backIndex] == '<')
            bracketsFromBack--;

    while (reader[backIndex] != '>')
    {
        faction = reader[backIndex] + faction;
        backIndex--;
    }
}

void customParser::findTimeAndDate()
{
    std::getline(htmlStream, reader);
    std::getline(htmlStream, reader);
    std::getline(htmlStream, reader);

    int bracketsFromBack = 1;
    int backIndex;
    for (backIndex = reader.length() - 1; bracketsFromBack; backIndex--)
        if (reader[backIndex] == ']')
            bracketsFromBack--;

    while (reader[backIndex] != '[')
    {
        time = reader[backIndex] + time;
        backIndex--;
    }

    while (reader[backIndex] != '<')
        backIndex--;
    backIndex -= 2;

    while (reader[backIndex] != '>')
    {
        date = reader[backIndex] + date;
        backIndex--;
    }
}
