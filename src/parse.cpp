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

    for (size_t size = 0; size <= str.length(); size++) {
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

int Circuit::parsing(char **argv)
{
    std::string toFind = argv[1];
    size_t found = toFind.find(".nts");
    std::ifstream input(argv[1]);

    if (found > 0) {
        for(std::string line; getline(input,line);) {
            line = removeBadChar(line);
            tabFile.push_back(line);
        }
        for(size_t size = 0; size <= (tabFile.size() - 1); size++) {
            if (tabFile[size][0] != '#') {
                if (size > 0 && strcmp(tabFile[size - 1].c_str(), ".chipsets:") == 0) {
                    for (;strcmp(tabFile[size + 1].c_str(), ".links:") != 0; size++)
                        chipsets.push_back(tabFile[size]);
                }
                if (size > 0 && strcmp(tabFile[size - 1].c_str(), ".links:") == 0) {
                    for (;size <= (tabFile.size() - 1); size++)
                        links.push_back(tabFile[size]);
                }
            }
        }
    } else
        throw;
    return (1);
}