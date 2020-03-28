/*
** EPITECH PROJECT, 2020
** Icomponent.hpp
** File description:
** IComponent.hpp
*/

#include <iostream>

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
        public :
            virtual ~IComponent() = default;
            virtual void dump() = 0;
            virtual void display() = 0;
            virtual void simulate() = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */