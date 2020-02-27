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
        int input_changes(Parser *, std::string);
        bool add_input(std::string, int, Parser *);

    protected:
        std::string getName();
        void setName(std::string Name);
        size_t getnbInputs();
        size_t getnbOutputs();

        std::string getInputsName(int i);
        void setInputsName(std::vector<std::string> Inputs);
        nts::Tristate getInputsValue(int i);
        void setInputsValue(std::vector<nts::Tristate> value);
        
        std::string getOutputsName(int i);
        void setOutputsName(std::vector<std::string> Inputs);
        nts::Tristate getOutputsValue(int i);
        void setOutputsValue(std::vector<nts::Tristate> value);

        nts::Tristate and_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate not_gate(nts::Tristate a);
        nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b);

    private:
        std::string name;

        std::vector<std::string> inputsName;
        std::vector<nts::Tristate> inputValue;

        std::vector<std::string> OutputsName;
        std::vector<nts::Tristate> OutputsValue;

        size_t nb;
        size_t nbO;
};

#endif /* !COMPONENT_HPP_ */