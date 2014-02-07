#include <iostream>
#include <string>

#include "xigua.hpp"

int main(int argc, char *argv [])
{ 
	std::cout << "Xigua REPL" << std::endl;
	xig::enviroment enviroment = xig::get_global_enviroment();
	std::string input;
	while (std::getline(std::cin, input)) {
		if (input == "exit") break;
		try {
			std::cout << xig::string_representation(xig::evaluate(enviroment, xig::parser::from_string(input))) << std::endl;
		} catch (xig::error e) {
			e.print_default_message();
		}
	}
}