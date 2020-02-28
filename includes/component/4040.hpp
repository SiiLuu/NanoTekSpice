/*
** EPITECH PROJECT, 2020
** 4040.hpp
** File description:
** 4040.hpp
*/

#ifndef _4040_HPP_
#define _4040_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4040 : public Component {
    public:
        _4040(Parser *);
        ~_4040();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4040_HPP_ */
