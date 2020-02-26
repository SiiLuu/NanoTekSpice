/*
** EPITECH PROJECT, 2020
** component.hpp
** File description:
** component.hpp
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "circuit.hpp"

class Component : Circuit {
    public:
        virtual void dump() = 0;

    protected:
        std::string getName();
        void setName(std::string Name);
        //std::string getInput();
        //void setInput(std::string Input);
        //std::string getOutput();
        //void setOutput(std::string Output);

    private:
        std::string name;
        nts::Tristate input;
        nts::Tristate output;
};

#endif /* !COMPONENT_HPP_ */