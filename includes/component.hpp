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
        virtual void dump()  = 0;

    protected:
        std::string getName();
        void setName(std::string Name);

    private:
        std::string name;
};

#endif /* !COMPONENT_HPP_ */