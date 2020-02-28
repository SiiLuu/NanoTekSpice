/*
** EPITECH PROJECT, 2020
** 4017.hpp
** File description:
** 4017.hpp
*/

#ifndef _4017_HPP_
#define _4017_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4017 : public Component {
    public:
        _4017(Parser *);
        ~_4017();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4017_HPP_ */
