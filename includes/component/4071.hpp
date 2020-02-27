/*
** EPITECH PROJECT, 2020
** 4011.hpp
** File description:
** 4011.hpp
*/

#ifndef _4071_HPP_
#define _4071_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4071 : public Component {
    public:
        _4071(Parser *);
        ~_4071();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4011_HPP_ */
