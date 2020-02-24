/*
** EPITECH PROJECT, 2020
** circuit.cpp
** File description:
** circuit.cpp
*/

#include <signal.h>
#include <stdbool.h>
#include "circuit.hpp"

Circuit::Circuit() {}

Circuit::~Circuit() {}

void Circuit::StartSimulation()
{
    std::cout << "FDP" << std::endl;
    DisplayPrompt();
    while (std::getline(std::cin, _line) && _line != "exit") {
        if (_line == "display") {
            display();
            DisplayPrompt();
        }
        else if (_line == "simulate") {
            simulate();
            DisplayPrompt();
        }
        else if (_line == "loop") {
            loop();
            DisplayPrompt();
        }
        else if (_line == "dump") {
            dump();
            DisplayPrompt();
        }
        else
            DisplayPrompt();
    }
}