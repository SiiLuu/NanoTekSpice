/*
** EPITECH PROJECT, 2020
** parse.cpp
** File description:
** parse.cpp
*/

#include "circuit.hpp"

int Circuit::parsing(char **argv)
{
    std::string toFind = argv[1];
    size_t found = toFind.find(".nts");
    std::ifstream input(argv[1]);

    if (found > 0) {
        for(std::string line; getline(input,line);)
            tabFile.push_back(line);
        for(size_t size = 0; size <= (tabFile.size() - 1); size++) {
            if (tabFile[size][0] != '#') {
                if (tabFile[size - 1] == ".chipsets:") {
                    for (;tabFile[size + 1] != ".links:"; size++)
                        chipsets.push_back(tabFile[size]);
                }
                if (!tabFile[size - 1].compare(".links:")) {
                    for (;size <= (tabFile.size() - 1); size++)
                        links.push_back(tabFile[size]);
                }
            }
        }
    } else
        throw;
    return (1);
}