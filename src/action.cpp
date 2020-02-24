/*
** EPITECH PROJECT, 2020
** circuit.cpp
** File description:
** circuit.cpp
*/

#include <signal.h>
#include <stdbool.h>
#include "circuit.hpp"

volatile int g_running = 1;

void  sig_handler(int signum)
{
    if (signum == SIGINT)
        g_running = 0;
}

void Circuit::DisplayPrompt()
{
    std::cout << "> ";
}

void Circuit::display()
{
    std::cout << "FDP" << std::endl;
}

void  Circuit::simulate()
{

}

void  Circuit::loop()
{
    signal(SIGINT, &sig_handler);
    while (g_running) {
        simulate();
    }
}

void  Circuit::dump()
{

}