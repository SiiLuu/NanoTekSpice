/*
** EPITECH PROJECT, 2020
** parse.cpp
** File description:
** parse.cpp
*/

#include "circuit.hpp"
#include <algorithm>
#include <cstring>

void Circuit::find_gate(size_t size)
{
    std::string nbr;
    std::string name;
    bool space = false;

    if (isdigit(this->tabFile[size][0])) {
        for (int i = 0; this->tabFile[size][i] != '\0'; i++) {
            if (this->tabFile[size][i] == ' ') {
                space = true;
                i++;
            }
            if (!space)
                nbr += this->tabFile[size][i];
            else
                name += this->tabFile[size][i];
        }
    }
    if (space)
        this->chipsets.insert(std::pair<std::string, int>(name, std::stoi(nbr)));
}

void Circuit::find_input(size_t size)
{
    std::string name;
    bool found = false;
    int i = 0;

    if (strncmp(this->tabFile[size].c_str(), "input", 5) == 0) {
        for (; this->tabFile[size][i] != ' '; i++);
        i++;
        for (; this->tabFile[size][i] != '\0' && this->tabFile[size][i] != ' '; i++)
            name += this->tabFile[size][i];
        found = true;
    }
    if (found)
        this->input.insert(std::pair<std::string, nts::Tristate>(name, nts::Tristate::UNDEFINED));
}

void Circuit::find_output(size_t size)
{
    std::string name;
    bool found = false;
    int i = 0;

    if (strncmp(this->tabFile[size].c_str(), "output", 6) == 0) {
        for (; this->tabFile[size][i] != ' '; i++);
        i++;
        for (; this->tabFile[size][i] != '\0' && this->tabFile[size][i] != ' '; i++)
            name += this->tabFile[size][i];
        found = true;
    }
    if (found)
        this->output.insert(std::pair<std::string, nts::Tristate>(name, nts::Tristate::UNDEFINED));
}

void Circuit::find_links_gate(size_t size)
{
    std::string str1;
    std::string str2;
    size_t i = 0;

    for (; this->tabFile[size][i] != ' '; i++)
        str1 += this->tabFile[size][i];
    i++;
    for (; this->tabFile[size][i] != '\0'; i++)
        str2 += this->tabFile[size][i];
    this->links.insert(std::pair<std::string, std::string>(str1, str2));
}

void Circuit::find_chipsets(size_t size)
{
    if (size > 0 && strcmp(this->tabFile[size - 1].c_str(), ".chipsets:") == 0)
        for (;strcmp(this->tabFile[size + 1].c_str(), ".links:") != 0; size++) {
            find_gate(size);
            find_input(size);
            find_output(size);
        }
}

void Circuit::find_links(size_t size)
{
    if (size > 0 && strcmp(this->tabFile[size - 1].c_str(), ".links:") == 0)
        for (;size <= (this->tabFile.size() - 1); size++)
            find_links_gate(size);
}

void Circuit::find_chipsets_and_links()
{
    for(size_t size = 0; size <= (this->tabFile.size() - 1); size++) {
        find_chipsets(size);
        find_links(size);
    }
}

int Circuit::parsing(int argc, std::vector<std::string> argv)
{
    std::fstream input;
    int check_is_good = 0;

    if (check_good_arguments(argc, argv) == 84)
        return (84);
    input.open(argv[1]);
    if (input && !input.fail()) {
        for(std::string line; getline(input,line);) {
            line = removeBadChar(line);
            if (strcmp(line.c_str(), "") == 0)
                continue;
            if (line[0] != '#')
                this->tabFile.push_back(line);
            if (strcmp(line.c_str(), ".links:") == 0 || strcmp(line.c_str(), ".chipsets:") == 0)
                check_is_good++;
        }
        //find_chipsets_and_links();
    } else {
        std::cout << "Bad file" << std::endl;
        return (84);
    }
    if (check_is_good != 2)
        return (84);
    return (1);
}
