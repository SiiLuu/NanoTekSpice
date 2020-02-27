/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** 4081
*/

#ifndef _4081_HPP_
#define _4081_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4081 : public Component {
    public:
        _4081(Parser *);
        ~_4081();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4081_HPP_ */
