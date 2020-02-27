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

Circuit::Circuit() {}

Circuit::~Circuit() {}

void  Circuit::sig_handler(int signum)
{
    if (signum == SIGINT)
        LOOP = false;
}

void Circuit::DisplayPrompt()
{
    std::cout << "> ";
}

int Circuit::StartSimulation(int argc, std::vector<std::string> argv)
{
    this->parse = new Parser;
    if (this->parse->parsing(argc, argv) == 84)
        return (84);
    std::signal(SIGINT, &Circuit::sig_handler);
    Component *component = Factory::createComponent(4081);/*
    component->simulate();
    component->display();
    DisplayPrompt();
    while (std::getline(std::cin, _line) && _line != "exit") {
        if (_line == "display") {
            component->display();
            DisplayPrompt();
        }
        else if (_line == "simulate") {
            component->simulate();
            DisplayPrompt();
        }
        else if (_line == "loop") {
            while (LOOP)
                component->simulate();
            DisplayPrompt();
        }
        else if (_line == "dump") {
            component->dump();
            DisplayPrompt();
        }
        else
            DisplayPrompt();
    }*/
    return (1);
}