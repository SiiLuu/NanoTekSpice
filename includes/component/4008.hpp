/*
** EPITECH PROJECT, 2020
** 4008.hpp
** File description:
** 4008.hpp
*/

#ifndef _4008_HPP_
#define _4008_HPP_

#include "gate.hpp"
#include "component.hpp"

class _4008 : public Component {
    public:
        _4008(Parser *);
        ~_4008();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !4008_HPP_ */
