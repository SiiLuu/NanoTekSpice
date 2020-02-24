/*
** EPITECH PROJECT, 2020
** circuit.hpp
** File description:
** circuit.hpp
*/

#include "IComponent.hpp"

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

class Circuit : public nts::IComponent {
    public:
        Circuit();
        ~Circuit();
        void DisplayPrompt();
        void display();
        void simulate();
        void loop();
        void dump();
        void StartSimulation();

    protected:
    private:
        std::string _line;
};

#endif /* !CIRCUIT_HPP_ */