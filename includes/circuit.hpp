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

    protected:
        
    private:
        std::string _line;
        void DisplayPrompt();
        static void sig_handler(int);
};

#endif /* !CIRCUIT_HPP_ */