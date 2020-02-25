/*
** EPITECH PROJECT, 2020
** factory.hpp
** File description:
** factory.hpp
*/

#include "component.hpp"

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

class Factory : Component {
    public:
        Factory();
        ~Factory();
        Component createComponent(std::string Name);

    protected:
    private:
};

#endif /* !FACTORY_HPP_ */
