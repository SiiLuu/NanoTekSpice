/*
** EPITECH PROJECT, 2020
** component.cpp
** File description:
** component.cpp
*/

#include "component.hpp"

std::string Component::getName()
{
    return (name);
}

void Component::setName(std::string Name)
{
    name = Name;
}

std::string Component::getInputsName(int i)
{
    return (inputsName[i]);
}

void Component::setInputsName(std::vector<std::string> Input)
{
    inputsName = Input;
}

size_t Component::getnbInputs()
{
    return (inputsName.size());
}

size_t Component::getnbOutputs()
{
    return (OutputsName.size());
}

nts::Tristate Component::getInputsValue(int i)
{
    return (inputValue[i]);
}

nts::Tristate Component::getOutputsValue(int i)
{
    return (OutputsValue[i]);
}

void Component::setInputsValue(std::vector<nts::Tristate> value)
{
    inputValue = value;
}

void Component::setOutputsValue(std::vector<nts::Tristate> value)
{
    OutputsValue = value;
}

std::string Component::getOutputsName(int i)
{
    return (OutputsName[i]);
}

void Component::setOutputsName(std::vector<std::string> Input)
{
    OutputsName = Input;
}

nts::Tristate Component::and_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    else if ((a == nts::Tristate::TRUE && b == nts::Tristate::FALSE) || \
            (a == nts::Tristate::FALSE && b == nts::Tristate::TRUE) || \
            (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE))
        return (nts::Tristate::FALSE);
    else if ((a == nts::Tristate::FALSE && b == nts::Tristate::UNDEFINED) || \
            (a == nts::Tristate::UNDEFINED && b == nts::Tristate::FALSE))
        return (nts::Tristate::FALSE);
    return (nts::Tristate::UNDEFINED);
}

nts::Tristate Component::or_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    else if ((a == nts::Tristate::TRUE && b == nts::Tristate::FALSE) || \
            (a == nts::Tristate::FALSE && b == nts::Tristate::TRUE))
        return (nts::Tristate::TRUE);
    else if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    else if ((a == nts::Tristate::TRUE && b == nts::Tristate::UNDEFINED) || \
            (a == nts::Tristate::UNDEFINED && b == nts::Tristate::TRUE))
        return (nts::Tristate::TRUE);
    return (nts::Tristate::UNDEFINED);
}

nts::Tristate Component::xor_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else if ((a == nts::Tristate::TRUE && b == nts::Tristate::FALSE) || \
            (a == nts::Tristate::FALSE && b == nts::Tristate::TRUE))
        return (nts::Tristate::TRUE);
    else if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    return (nts::Tristate::UNDEFINED);
}

nts::Tristate Component::not_gate(nts::Tristate a)
{
    if (a == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else if (a == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    return (nts::Tristate::UNDEFINED);
}