/*
** EPITECH PROJECT, 2020
** circuit.cpp
** File description:
** circuit.cpp
*/

#include "circuit.hpp"

Circuit::Circuit() {}

Circuit::~Circuit() {}

void Circuit::DisplayPrompt() const
{
    std::cout << "> ";
}

void Circuit::StartSimulation()
{
    this->DisplayPrompt();
    while (std::getline(std::cin, _line) && _line != "exit") {
        this->DisplayPrompt();
        
    }
}