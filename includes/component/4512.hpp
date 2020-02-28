/*
** EPITECH PROJECT, 2020
** 4512.hpp
** File description:
** 4512.hpp
*/

#ifndef _4512_HPP_
#define _4512_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4512 : public Component {
    public:
        _4512(Parser *);
        ~_4512();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4512_HPP_ */
