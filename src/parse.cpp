/*
** EPITECH PROJECT, 2020
** parse.cpp
** File description:
** parse.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>

int parsing(char **argv)
{
    std::string toFind = argv[1];
    size_t found = toFind.find(".nts");
    std::ifstream input(argv[1]);
    std::vector<std::string> tabFile;
    std::vector<std::string> chipsets;
    std::vector<std::string> links;

    if (found > 0) {
        for(std::string line; getline(input,line);)
            tabFile.push_back(line);
        for(size_t size = 0; size <= (tabFile.size() - 1); size++) {
            if (tabFile[size][0] != '#') {
                if (tabFile[size] == ".chipsets:") {
                    for (;tabFile[size] != ".links:"; size++)
                        chipsets.push_back(tabFile[size]);
                }
                if (!tabFile[size].compare(".links:")) {
                    for (;size <= tabFile.size(); size++)
                        links.push_back(tabFile[size]);
                }
            }
        }
    } else
        throw;
    for(size_t size = 0; size <= (tabFile.size() - 1); size++)
        std::cout << "tabFile: " << tabFile[size] << std::endl;
    for(size_t size = 0; size <= (chipsets.size() - 1); size++)
        std::cout << "chipsets: " << chipsets[size] << std::endl;
    for(size_t size = 0; size <= (links.size() - 1); size++)
        std::cout << "links: " << links[size] << std::endl;
    return (1);
}