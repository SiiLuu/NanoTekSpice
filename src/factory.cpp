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
		case 4030:{
			component = new _4030(parse);
			break;
		}
		case 4071:{
			component = new _4071(parse);
			break;
		}
		case 4001:{
			component = new _4001(parse);
			break;
		}
		case 4011:{
			component = new _4011(parse);
			break;
		}
		case 2716:{
			component = new _2716(parse);
			break;
		}
		case 4008:{
			component = new _4008(parse);
			break;
		}
		case 4013:{
			component = new _4013(parse);
			break;
		}
		case 4017:{
			component = new _4017(parse);
			break;
		}
		case 4040:{
			component = new _4040(parse);
			break;
		}
		case 4069:{
			component = new _4069(parse);
			break;
		}
		case 4094:{
			component = new _4094(parse);
			break;
		}
		case 4503:{
			component = new _4503(parse);
			break;
		}
		case 4512:{
			component = new _4512(parse);
			break;
		}
		case 4514:{
			component = new _4514(parse);
			break;
		}
		default:{
			std::cout << "invalid" << std::endl;
			return nullptr;
		}
	}
	return component;
}