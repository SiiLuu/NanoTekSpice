/*
** EPITECH PROJECT, 2020
** component.cpp
** File description:
** component.cpp
*/

#include "component.hpp"

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