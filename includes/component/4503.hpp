/*
** EPITECH PROJECT, 2020
** 4503.hpp
** File description:
** 4503.hpp
*/

#ifndef _4503_HPP_
#define _4503_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4503 : public Component {
    public:
        _4503(Parser *);
        ~_4503();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4503_HPP_ */
