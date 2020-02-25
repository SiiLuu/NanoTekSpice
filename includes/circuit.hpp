/*
** EPITECH PROJECT, 2020
** circuit.hpp
** File description:
** circuit.hpp
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class Circuit : public nts::IComponent {
    public:
        Circuit();
        ~Circuit();
        void StartSimulation();
        void parsing(char **);
        
        std::vector<std::string> tabFile;
        std::vector<std::string> chipsets;
        std::vector<std::string> links;

    protected:
    private:
        std::string _line;
        void DisplayPrompt();
        void display();
        void simulate();
        void loop();
        void dump();
        static void sig_handler(int );
        void find_chipsets_and_links();
        void find_links(size_t);
        void find_chipsets(size_t);
};

#endif /* !CIRCUIT_HPP_ */