/*
** EPITECH PROJECT, 2020
** 2716.hpp
** File description:
** 2716.hpp
*/

#ifndef _2716_HPP_
#define _2716_HPP_

#include "gate.hpp"
#include "component.hpp"

class _2716 : public Component {
    public:
        _2716(Parser *);
        ~_2716();
        Parser *_parse;
        void dump();
        void display();
        void simulate();

    protected:
    private:
};

#endif /* !2716_HPP_ */
