/*
** EPITECH PROJECT, 2020
** 4069.hpp
** File description:
** 4069.hpp
*/

#ifndef _4069_HPP_
#define _4069_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4069 : public Component {
    public:
        _4069(Parser *);
        ~_4069();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4069_HPP_ */
