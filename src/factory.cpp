/*
** EPITECH PROJECT, 2020
** factory.cpp
** File description:
** factory.cpp
*/

#include "factory.hpp"

Factory::Factory() {}

Factory::~Factory() {}

Component *Factory::createComponent(int type, Parser *parse)
{
	Component *component = nullptr;

	switch(type) {
		case 4081:{
			component = new _4081(parse);
			break;
		}
		default:{
			std::cout << "invalid" << std::endl;
			return nullptr;
		}
	}
	return component;
}