/*
** EPITECH PROJECT, 2020
** 4514.hpp
** File description:
** 4514.hpp
*/

#ifndef _4514_HPP_
#define _4514_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4514 : public Component {
    public:
        _4514(Parser *);
        ~_4514();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4514_HPP_ */
