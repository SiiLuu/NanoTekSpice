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
#include <map>

class Circuit {
    public:
        Circuit();
        ~Circuit();
        void StartSimulation();

        int parsing(int, std::vector<std::string>);
        std::vector<std::string> tabFile;
        std::map<std::string, int> chipsets;
        std::map<std::string, nts::Tristate> input;
        std::map<std::string, nts::Tristate> output;
        std::map<std::string, std::string> links;

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
        void find_gate(size_t size);
        void find_input(size_t size);
        void find_output(size_t size);
        void find_links_gate(size_t size);
};

int check_good_value(std::string str);
int check_good_arguments(int argc, std::vector<std::string> argv);
std::string removeBadChar (std::string str);

#endif /* !CIRCUIT_HPP_ */