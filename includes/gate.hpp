/*
** EPITECH PROJECT, 2020
** gate.hpp
** File description:
** gate.hpp
*/

#ifndef GATE_HPP_
#define GATE_HPP_

#include <component.hpp>

class Gate : Component {
    public:
        Gate();
        ~Gate();
        nts::Tristate and_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate not_gate(nts::Tristate a);
        nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b);


    protected:
    private:
};

#endif /* !GATE_HPP_ */