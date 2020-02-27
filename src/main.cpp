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

    std::vector<std::string> av(argv, argv + argc);
    if (circ.StartSimulation(argc, av) == 84)
        return (84);
    //for (size_t i = 0; i <= circ.tabFile.size(); i++)
    //    std::cout << circ.tabFile[i] << std::endl;
/*
    std::cout << "Chipsets: " << std::endl;
    for(auto it = circ.chipsets.cbegin(); it != circ.chipsets.cend(); ++it)
        std::cout << it->first << " " << it->second << " " << "\n";
    std::cout << "Input" << std::endl;
    for(auto it = circ.input.cbegin(); it != circ.input.cend(); ++it)
        std::cout << it->first << " " << it->second << " " << "\n";
    std::cout << "Output" << std::endl;
    for(auto it = circ.output.cbegin(); it != circ.output.cend(); ++it)
        std::cout << it->first << " " << it->second << " " << "\n";
    std::cout << "Links" << std::endl;
    for(auto it = circ.links.cbegin(); it != circ.links.cend(); ++it)
        std::cout << it->first << " " << it->second << " " << "\n";
*/
    return (0);
}
