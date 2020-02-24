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

    //circ.StartSimulation();
    circ.parsing(argv);
    for(size_t size = 0; size <= (circ.chipsets.size() - 1); size++)
        std::cout << circ.chipsets[size] << std::endl;
    std::cout << std::endl;
    for(size_t size = 0; size <= (circ.links.size() - 1); size++)
        std::cout << circ.links[size] << std::endl;
    return (0);
}