/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
*/

#include "circuit.hpp"

int main(int argc, char **argv)
{
    Circuit circ;

    std::vector<std::string> av(argv + 1, argv + argc);
    if (circ.parsing(argc, av) == 84)
        return (84);
    circ.StartSimulation();
    return (0);
}