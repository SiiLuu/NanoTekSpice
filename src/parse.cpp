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

int check_good_value(std::string str)
{
    bool good = false;

    for (size_t i = 0; i <= str.length(); i++) {
        if (str[i] == '=')
            good = true;
        if (good) {
            if (isdigit(str[i]) == 0)
                return (84);
        }
    }
    return (1);
}

int check_good_arguments(int argc, std::vector<std::string> argv)
{
    if (argc < 2) {
        std::cout << "File is missing" << std::endl;
        return (84);
    }
    for (int i = 2; i < argc; i++)
        if (check_good_value(argv[i]) == 84)
            return (84);
    return (1);
}

int Circuit::parsing(int argc, std::vector<std::string> argv)
{
    //if (check_good_arguments(argc, argv) == 84)
    //    return (84);

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
        return (84);
    return (1);
}
