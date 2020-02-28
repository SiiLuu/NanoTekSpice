/*
** EPITECH PROJECT, 2020
** 4013.hpp
** File description:
** 4013.hpp
*/

#ifndef _4013_HPP_
#define _4013_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4013 : public Component {
    public:
        _4013(Parser *);
        ~_4013();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4013_HPP_ */
