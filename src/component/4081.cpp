/*
** EPITECH PROJECT, 2020
** 4081.cpp
** File description:
** 4081
*/

#include "4081.hpp"

_4081::_4081(Parser *parse)
{
    this->_parse = parse;
}

_4081::~_4081() {}

void _4081::dump()
{
    std::map<std::string, nts::Tristate>::iterator itI = _parse->input.begin();
    std::map<std::string, nts::Tristate>::iterator itO = _parse->output.begin();
    std::cout << "4081" << " Dumped" << std::endl;
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

void _4081::display()
{
    std::map<std::string, nts::Tristate>::iterator itO = _parse->output.begin();
    for(; itO != _parse->output.end(); ++itO) {
        if (itO->second == -1)
            std::cout << itO->first << "=U" << std::endl;
        else
            std::cout << itO->first << "=" << itO->second << std::endl;
    }
}

void _4081::simulate()
{
    std::map<std::string, nts::Tristate>::iterator itI = _parse->input.begin();
    std::map<std::string, nts::Tristate>::iterator jtI = _parse->input.begin();
    std::map<std::string, nts::Tristate>::iterator itO = _parse->output.begin();
    nts::Tristate temp;
    nts::Tristate temp2;
    nts::Tristate temp3;
    ++jtI;
    if (_parse->input.size() <= 2)
        itO->second = and_gate(itI->second, jtI->second);
    else {
        temp = and_gate(itI->second, jtI->second);
        ++jtI;
        ++jtI;
        ++itI;
        ++itI;
        temp2 = and_gate(itI->second, jtI->second);
        ++jtI;
        temp3 = and_gate(temp, temp2); 
        itO->second = and_gate(temp3, jtI->second);
        if (_parse->chipsets.size() > 1)
            itO->second = not_gate(itO->second);
    }
}