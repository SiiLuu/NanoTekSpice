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
#include "2716.hpp"
#include "4008.hpp"
#include "4013.hpp"
#include "4017.hpp"
#include "4040.hpp"
#include "4069.hpp"
#include "4094.hpp"
#include "4503.hpp"
#include "4512.hpp"
#include "4514.hpp"
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
