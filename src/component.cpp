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