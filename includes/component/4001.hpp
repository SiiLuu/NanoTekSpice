/*
** EPITECH PROJECT, 2020
** 4001.hpp
** File description:
** 4001.hpp
*/

#ifndef _4001_HPP_
#define _4001_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4001 : public Component {
    public:
        _4001(Parser *);
        ~_4001();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4001_HPP_ */
