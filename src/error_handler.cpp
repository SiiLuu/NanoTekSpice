/*
** EPITECH PROJECT, 2020
** error_handler.c
** File description:
** error_handler.c
*/

#include "parse.hpp"
#include "exception.hpp"

int Parser::check_good_value(std::string str)
{
    bool good = false;
    bool alphanumeric = false;

    for (size_t i = 0; i <= str.length(); i++) {
        if (str[i] == '=') {
            good = true;
            i++;
        }
        if (good && str[i] != '\0') {
            if (isdigit(str[i]) == 0)
                alphanumeric = false;
            else
                alphanumeric = true;
        }
    }
    if (alphanumeric)
        return (1);
    std::cout << "Error: Input" << std::endl;
    return (84);
}

int Parser::check_good_arguments(int argc, std::vector<std::string> argv)
{
    if (argc < 2) {
        std::cout << "File is missing" << std::endl;
        throw Exception ("Arguments not valid");
        return (1);
    }
    for (int i = 2; i < argc; i++) {
        if (check_good_value(argv[i]) == 84) {
            throw Exception ("Arguments not valid");
            return (1);
        }
    }
    return (1);
}

std::string Parser::removeBadChar (std::string str)
{
    std::string newStr;
    size_t size = 0;

    for (; size <= str.length(); size++) {
        if (str[size] == '#')
            for (; str[size] != '\0'; size++);
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

int Parser::all_value_set(void)
{
    bool error = false;

    for(auto it = input.cbegin(); it != input.cend(); ++it) {
        if (it->second == nts::Tristate::UNDEFINED) {
            std::cout << it->first << " is not set." << std::endl;
            error = true;
        }
    }
    for(auto it = clock.cbegin(); it != clock.cend(); ++it) {
        if (it->second == nts::Tristate::UNDEFINED) {
            error = true;
            std::cout << it->first << " is not set." << std::endl;
        }
    }
    if (error == true)
        throw Exception ("All value are not set");
    return (1);
}
