/*
** EPITECH PROJECT, 2020
** exception.hpp
** File description:
** exception.hpp
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <iostream>
#include <string>

class Exception : public std::exception
{
    public:
        Exception(const std::string &msg) : msg(msg){}

        virtual const char* what() const throw()
        {
            return (msg.c_str());
        }
    private:
        std::string msg;
};

#endif /* !EXCEPTION_HPP_ */
