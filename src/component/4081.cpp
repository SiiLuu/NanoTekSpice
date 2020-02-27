/*
** EPITECH PROJECT, 2020
** 4081.cpp
** File description:
** 4081
*/

#include "4081.hpp"
#include "parse.hpp"

_4081::_4081()
{
    Parser parse;

    for(auto it = parse.getInput().begin(); it != parse.getInput().end(); ++it)
        std::cout << it->first << " " << it->second << " " << "\n";
    setName("4081");
    setInputsName({"a", "b"});
    setOutputsName({"s"});
    setInputsValue({nts::Tristate::TRUE, nts::Tristate::FALSE});
    setOutputsValue({nts::Tristate::UNDEFINED});
}

_4081::~_4081() {}

void _4081::dump()
{
    std::cout << getName() << " Dumped" << std::endl;
    for (size_t i = 0; i < getnbInputs(); i++) {
        if (getInputsValue(i) == nts::Tristate::UNDEFINED)
            std::cout << getInputsName(i) << "=" << "U" << std::endl;
        else
            std::cout << getInputsName(i) << "=" << getInputsValue(i) << std::endl;
    }
    for (size_t i = 0; i < getnbOutputs(); i++) {
        if (getOutputsValue(i) == nts::Tristate::UNDEFINED)
            std::cout << getOutputsName(i) << "=" << "U" << std::endl;
        else
            std::cout  << getOutputsName(i) << "=" << getOutputsValue(i) << std::endl;
    }
}

void _4081::display()
{
    for (size_t i = 0; i < getnbOutputs(); i++) {
        if (getOutputsValue(i) == nts::Tristate::UNDEFINED)
            std::cout << getOutputsName(i) << "=" << "U" << std::endl;
        else
            std::cout << getOutputsName(i) << "=" << getOutputsValue(i) << std::endl;
    }
}

void _4081::simulate()
{
    setOutputsValue({and_gate(getInputsValue(0), getInputsValue(1))});
}