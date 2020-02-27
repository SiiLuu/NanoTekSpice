/*
** EPITECH PROJECT, 2020
** 4011.hpp
** File description:
** 4011.hpp
*/

#ifndef _4030_HPP_
#define _4030_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4030 : public Component {
    public:
        _4030(Parser *);
        ~_4030();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4011_HPP_ */
