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

    circ.parsing(argv);
    (void)argc;
    circ.StartSimulation();
    return (0);
}