/*
** EPITECH PROJECT, 2020
** component.hpp
** File description:
** component.hpp
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "circuit.hpp"

class Component : public Circuit {
    public:
        virtual void dump() = 0;
        virtual void display() = 0;
        virtual void simulate() = 0;

    protected:
        nts::Tristate and_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate not_gate(nts::Tristate a);
        nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b);

    private:
};

#endif /* !COMPONENT_HPP_ */