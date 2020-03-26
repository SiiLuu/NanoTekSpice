/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
*/

#include "circuit.hpp"
#include "exception.hpp"

int main(int argc, char **argv)
{
    Circuit circ;

    std::vector<std::string> av(argv, argv + argc);
    circ.StartSimulation(argc, av);
    return (0);
}
