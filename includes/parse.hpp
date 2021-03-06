/*
** EPITECH PROJECT, 2020
** circuit.hpp
** File description:
** circuit.hpp
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "IComponent.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

class Parser {
    public:
        std::vector<std::string> tabFile;
        std::map<std::string, int> chipsets;
        std::map<std::string, nts::Tristate> input;
        std::map<std::string, nts::Tristate> output;
        std::map<std::string, std::string> links;
        std::map<std::string, nts::Tristate> clock;
        std::map<std::string, bool> true_map;
        std::map<std::string, bool> false_map;
        int getI(void);
        int setI(void);
        int parsing(int, std::vector<std::string>);

    protected:
    private:
        void find_chipsets_and_links();
        void find_links(size_t);
        void find_chipsets(size_t);
        void find_gate(size_t size);
        void find_input(size_t size);
        void find_output(size_t size);
        void find_clocks(size_t size);
        void find_true(size_t size);
        void find_false(size_t size);
        void find_links_gate(size_t size);
        bool add_input_map(std::string, int);
        int put_input(int, std::vector<std::string>);
        int check_good_value(std::string str);
        int check_good_arguments(int argc, std::vector<std::string> argv);
        std::string removeBadChar (std::string str);
        int all_value_set(void);
};

#endif /* !PARSER_HPP_ */
