/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
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

int main(void)
{
    Circuit circ;

    circ.StartSimulation();
    return (0);
}