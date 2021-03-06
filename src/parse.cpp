/*
** EPITECH PROJECT, 2020
** parse.cpp
** File description:
** parse.cpp
*/

#include "exception.hpp"
#include "parse.hpp"
#include <algorithm>
#include <cstring>

bool Parser::add_input_map(std::string str, int nbr)
{
    bool error = true;

    if (nbr >= 2)
        return (true);
    for(auto it = this->input.begin(); it != this->input.end(); ++it) {
        if (it->first.compare(str) == 0) {
            it->second = static_cast<nts::Tristate>(nbr);
            error = false;
        }
    }
    if (error == true) {
        for(auto it = this->clock.begin(); it != this->clock.end(); ++it) {
            if (it->first.compare(str) == 0) {
                it->second = static_cast<nts::Tristate>(nbr);
                error = false;
            }
        }
    }
    if (error == true) {
        std::cout << "Error input" << std::endl;
        return (true);
    }
    return (false);
}

int Parser::put_input(int argc, std::vector<std::string> argv)
{
    bool good = false;
    bool error = false;
    std::string str;
    std::string nbr;

    if (argc == 2)
        return (1);
    for (int t = 2; t < argc; t++) {
        str.clear();
        nbr.clear();
        good = false;
        for (size_t i = 0; i <= argv[t].length(); i++) {
            if (argv[t][i] == '=') {
                i++;
                good = true;
            }
            if (!good)
                str += argv[t][i];
            else
                nbr += argv[t][i];
        }
        error = add_input_map(str, std::stoi(nbr));
    }
    if (good && !error)
        return (1);
    throw Exception ("Error in input");
    return (1);
}

void Parser::find_gate(size_t size)
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

void Parser::find_input(size_t size)
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

void Parser::find_output(size_t size)
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

void Parser::find_clocks(size_t size)
{
    std::string name;
    bool found = false;
    int i = 0;

    if (strncmp(this->tabFile[size].c_str(), "clock", 5) == 0) {
        for (; this->tabFile[size][i] != ' '; i++);
        i++;
        for (; this->tabFile[size][i] != '\0' && this->tabFile[size][i] != ' '; i++)
            name += this->tabFile[size][i];
        found = true;
    }
    if (found)
        this->clock.insert(std::pair<std::string, nts::Tristate>(name, nts::Tristate::UNDEFINED));
}

void Parser::find_true(size_t size)
{
    std::string name;
    bool found = false;
    int i = 0;

    if (strncmp(this->tabFile[size].c_str(), "true", 5) == 0) {
        for (; this->tabFile[size][i] != ' '; i++);
        i++;
        for (; this->tabFile[size][i] != '\0' && this->tabFile[size][i] != ' '; i++)
            name += this->tabFile[size][i];
        found = true;
    }
    if (found)
        this->true_map.insert(std::pair<std::string, bool>(name, true));
}

void Parser::find_false(size_t size)
{
    std::string name;
    bool found = false;
    int i = 0;

    if (strncmp(this->tabFile[size].c_str(), "false", 5) == 0) {
        for (; this->tabFile[size][i] != ' '; i++);
        i++;
        for (; this->tabFile[size][i] != '\0' && this->tabFile[size][i] != ' '; i++)
            name += this->tabFile[size][i];
        found = true;
    }
    if (found)
        this->false_map.insert(std::pair<std::string, bool>(name, false));
}

void Parser::find_links_gate(size_t size)
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

void Parser::find_chipsets(size_t size)
{
    if (size > 0 && strcmp(this->tabFile[size - 1].c_str(), ".chipsets:") == 0)
        for (;strcmp(this->tabFile[size].c_str(), ".links:") != 0; size++) {
            find_gate(size);
            find_input(size);
            find_output(size);
            find_clocks(size);
            find_true(size);
            find_false(size);
        }
}

void Parser::find_links(size_t size)
{
    if (size > 0 && strcmp(this->tabFile[size - 1].c_str(), ".links:") == 0)
        for (;size <= (this->tabFile.size() - 1); size++)
            find_links_gate(size);
}

void Parser::find_chipsets_and_links()
{
    for(size_t size = 0; size <= (this->tabFile.size() - 1); size++) {
        find_chipsets(size);
        find_links(size);
    }
}

int Parser::parsing(int argc, std::vector<std::string> argv)
{
    std::filebuf fb;
    int check_is_good = 0;

    try {
        check_good_arguments(argc, argv);
    }
    catch (Exception &e) {
        std::cout << e.what() << std::endl;
        exit (84);
    }
    if (fb.open(argv[1], std::ios::in)) {
        std::istream input(&fb);
        for(std::string line; getline(input,line);) {
            line = removeBadChar(line);
            if (strcmp(line.c_str(), "") == 0)
                continue;
            if (line[0] != '#')
                this->tabFile.push_back(line);
            if (strcmp(line.c_str(), ".links:") == 0 || strcmp(line.c_str(), ".chipsets:") == 0)
                check_is_good++;
        }
        find_chipsets_and_links();
    } else
        throw Exception ("Bad file");
    try {
        put_input(argc, argv);
    }
    catch (Exception &e) {
        std::cout << e.what() << std::endl;
        exit (84);
    }
    try {
        all_value_set();
    }
    catch (Exception &e) {
        std::cout << e.what() << std::endl;
        exit (84);
    }
    if (check_is_good != 2)
        throw Exception ("Bad arguments");
    return (1);
}
