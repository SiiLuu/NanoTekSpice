/*
** EPITECH PROJECT, 2020
** Icomponent.hpp
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

class IComponent {
    public:
        enum State {
            TRUE,
            FALSE,
            UNDEFINED
        };
        IComponent();
        ~IComponent();

    protected:
    private:
};

#endif /* !ICOMPONENT_HPP_ */