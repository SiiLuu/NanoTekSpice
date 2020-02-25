/*
** EPITECH PROJECT, 2020
** parse.cpp
** File description:
** parse.cpp
*/

#include "circuit.hpp"
#include <algorithm>
#include <cstring>

std::string removeBadChar (std::string str)
{
    std::string newStr;
    size_t size = 0;

    for (; size <= str.length(); size++) {
        if (str[size] && (str[size] == ' ' || str[size] == '\t')) {
            for (; str[size] && (str[size] == ' ' || str[size] == '\t'); size++) {
                if (str[size + 1] != ' ' && str[size + 1] != '\t') {
                    str[size] = ' ';
                    break;
                }
            }
        }
        newStr += str[size];
    }
    return (newStr);
}

void Circuit::find_chipsets(size_t size)
{
    if (size > 0 && strcmp(this->tabFile[size - 1].c_str(), ".chipsets:") == 0) {
        for (;strcmp(this->tabFile[size + 1].c_str(), ".links:") != 0; size++)
            this->chipsets.push_back(this->tabFile[size]);
    }
}

void Circuit::find_links(size_t size)
{
    if (size > 0 && strcmp(this->tabFile[size - 1].c_str(), ".links:") == 0) {
        for (;size <= (this->tabFile.size() - 1); size++)
            this->links.push_back(this->tabFile[size]);
    }
}

void Circuit::find_chipsets_and_links()
{
    for(size_t size = 0; size <= (this->tabFile.size() - 1); size++) {
        if (this->tabFile[size][0] != '#') {
            find_chipsets(size);
            find_links(size);
        }
    }
}

void Circuit::parsing(char **argv)
{
    std::string toFind = argv[1];
    size_t found = toFind.find(".nts");
    std::ifstream input(argv[1]);

    if (found > 0) {
        for(std::string line; getline(input,line);) {
            line = removeBadChar(line);
            this->tabFile.push_back(line);
        }
        find_chipsets_and_links();
    } else
        throw;
}
