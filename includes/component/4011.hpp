/*
** EPITECH PROJECT, 2020
** 4011.hpp
** File description:
** 4011.hpp
*/

#ifndef _4011_HPP_
#define _4011_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4011 : public Component {
    public:
        _4011(Parser *);
        ~_4011();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4011_HPP_ */
