/*
** EPITECH PROJECT, 2020
** circuit.cpp
** File description:
** circuit.cpp
*/

#include <csignal>
#include <stdbool.h>
#include "circuit.hpp"
#include "factory.hpp"

bool LOOP = true;

void  Circuit::sig_handler(int signum)
{
    if (signum == SIGINT)
        LOOP = false;
}

void Circuit::DisplayPrompt()
{
    std::cout << "> ";
}

void Circuit::display()
{
    std::cout << "FDP" << std::endl;
}

void  Circuit::simulate()
{

}

void  Circuit::loop()
{
    std::signal(SIGINT, &Circuit::sig_handler);
    while (LOOP) {
        simulate();
    }
}

void  Circuit::dump()
{
    Component *component = Factory::createComponent(4081);
}