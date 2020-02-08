/*
** EPITECH PROJECT, 2020
** operators.cpp
** File description:
** operators.cpp
*/

#include "IComponent.hpp"

IComponent::State operator&&(IComponent::State a, IComponent::State b)
{
    if (a == IComponent::State::TRUE && b == IComponent::State::TRUE)
        return (IComponent::State::TRUE);
    else if ((a == IComponent::State::TRUE && b == IComponent::State::FALSE) || \
             (a == IComponent::State::FALSE && b == IComponent::State::TRUE) || \
             (a == IComponent::State::FALSE && b == IComponent::State::FALSE))
        return (IComponent::State::FALSE);
    else if ((a == IComponent::State::FALSE && b == IComponent::State::UNDEFINED) || \
             (a == IComponent::State::UNDEFINED && b == IComponent::State::FALSE))
        return (IComponent::State::FALSE);
    return (IComponent::State::UNDEFINED);
}

IComponent::State operator||(IComponent::State a, IComponent::State b)
{
    if (a == IComponent::State::TRUE && b == IComponent::State::TRUE)
        return (IComponent::State::TRUE);
    else if ((a == IComponent::State::TRUE && b == IComponent::State::FALSE) || \
             (a == IComponent::State::FALSE && b == IComponent::State::TRUE))
        return (IComponent::State::TRUE);
    else if (a == IComponent::State::FALSE && b == IComponent::State::FALSE)
        return (IComponent::State::FALSE);
    else if ((a == IComponent::State::TRUE && b == IComponent::State::UNDEFINED) || \
             (a == IComponent::State::UNDEFINED && b == IComponent::State::TRUE))
        return (IComponent::State::TRUE);
    return (IComponent::State::UNDEFINED);
}

IComponent::State operator^(IComponent::State a, IComponent::State b)
{
    if (a == IComponent::State::TRUE && b == IComponent::State::TRUE)
        return (IComponent::State::FALSE);
    else if ((a == IComponent::State::TRUE && b == IComponent::State::FALSE) || \
             (a == IComponent::State::FALSE && b == IComponent::State::TRUE))
        return (IComponent::State::TRUE);
    else if (a == IComponent::State::FALSE && b == IComponent::State::FALSE)
        return (IComponent::State::FALSE);
    return (IComponent::State::UNDEFINED);
}

IComponent::State operator~(IComponent::State a)
{
    if (a == IComponent::State::TRUE)
        return (IComponent::State::FALSE);
    else if (a == IComponent::State::FALSE)
        return (IComponent::State::TRUE);
    return (IComponent::State::UNDEFINED);
}