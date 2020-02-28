/*
** EPITECH PROJECT, 2020
** component.cpp
** File description:
** component.cpp
*/

#include "component.hpp"

bool Component::add_input(std::string str, int nbr, Parser *parse)
{
    bool error = true;

    if (nbr >= 2)
        return (true);
    for(auto it = parse->input.begin(); it != parse->input.end(); ++it) {
        if (it->first.compare(str) == 0) {
            it->second = static_cast<nts::Tristate>(nbr);
            error = false;
        }
    }
    if (error == true)
        return (true);
    return (false);
}

int Component::input_changes(Parser *parse, std::string str)
{
    std::string name;
    std::string value;
    bool good = false;
    bool error = false;

    for (size_t i = 0; i <= str.length(); i++) {
        if (str[i] == '=') {
            i++;
            good = true;
        }
        if (!good)
            name += str[i];
        else
            value += str[i];
    }
    error = add_input(name, std::stoi(value), parse);
    if (good && !error)
        return (1);
    return (84);
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