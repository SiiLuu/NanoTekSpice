/*
** EPITECH PROJECT, 2020
** 4094.hpp
** File description:
** 4094.hpp
*/

#ifndef _4094_HPP_
#define _4094_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4094 : public Component {
    public:
        _4094(Parser *);
        ~_4094();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4094_HPP_ */
