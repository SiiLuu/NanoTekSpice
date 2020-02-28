/*
** EPITECH PROJECT, 2020
** 4503.cpp
** File description:
** 4503.cpp
*/

#include "4503.hpp"

_4503::_4503(Parser *parse)
{
    this->_parse = parse;
}

_4503::~_4503() {}

void _4503::dump()
{
    std::map<std::string, nts::Tristate>::iterator itI = _parse->input.begin();
    std::map<std::string, nts::Tristate>::iterator itO = _parse->output.begin();
    std::cout << "4503" << " Dumped" << std::endl;
    for(; itI != _parse->input.end(); ++itI) {
        if (itI->second == -1)
            std::cout << itI->first << "=U" << std::endl;
        else
            std::cout << itI->first << "=" << itI->second << std::endl;
    }
    for(; itO != _parse->output.end(); ++itO) {
        if (itO->second == -1)
            std::cout << itO->first << "=U" << std::endl;
        else
            std::cout << itO->first << "=" << itO->second << std::endl;
    }
}

void _4503::display()
{
    std::map<std::string, nts::Tristate>::iterator itO = _parse->output.begin();
    for(; itO != _parse->output.end(); ++itO) {
        if (itO->second == -1)
            std::cout << itO->first << "=U" << std::endl;
        else
            std::cout << itO->first << "=" << itO->second << std::endl;
    }
}

void _4503::simulate()
{
    std::map<std::string, nts::Tristate>::iterator itI = _parse->input.begin();
    std::map<std::string, nts::Tristate>::iterator jtI = _parse->input.begin();
    std::map<std::string, nts::Tristate>::iterator itO = _parse->output.begin();
    ++jtI;
    itO->second = or_gate(itI->second, jtI->second);
    itO->second = not_gate(itO->second);
}