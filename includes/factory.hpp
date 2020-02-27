/*
** EPITECH PROJECT, 2020
** factory.hpp
** File description:
** factory.hpp
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <iostream>
#include "4081.hpp"
#include "4001.hpp"
#include "4011.hpp"
#include "4030.hpp"
#include "4071.hpp"
#include "component.hpp"

class Factory {
    public:
        Factory();
        ~Factory();
        static Component *createComponent(int type, Parser *);

    protected:
    private:
};

#endif /* !FACTORY_HPP_ */
