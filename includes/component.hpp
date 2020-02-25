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
    protected:
        std::string getName() { return (name); }
        //virtual nts::Tristate getInput1();
        //virtual nts::Tristate getInput2();
        //virtual nts::Tristate getOutput();
        void setName(std::string Name) { name = Name; }
        //virtual void setInput1(nts::Tristate input);
        //virtual void setInput2(nts::Tristate input);
        //virtual void setOutput(nts::Tristate output);

    private:
        //virtual nts::Tristate input1;
        //virtual nts::Tristate input2;
        //virtual nts::Tristate output;
        std::string name;
};

#endif /* !COMPONENT_HPP_ */