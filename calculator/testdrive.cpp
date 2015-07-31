#include "calc.hpp"
#include <iostream>
namespace
{
int getIntInput() {
	int num = 0;
	while(!(std::cin >> num)){
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input. Try again: " << std::endl;
	}
	return num;
}
}
int main() {
	MyCalc calc;

	std::cout << "Enter your first number: " << std::endl;
	int first_num = getIntInput();

	std::cout << "Enter your second number: " << std::endl;
	int second_num = getIntInput();

	std::cout << "Enter an operator (+,-,*,/,e(exit))" << std::endl;
	char operator_sign = '+';
	std::cin >> operator_sign;
	while (operator_sign) {
		if (operator_sign == '+') {
			std::cout << "Sum: " << calc.Add(first_num, second_num) << std::endl;
		} else if (operator_sign == '-') {
			std::cout << "Difference: " << calc.Subtract(first_num, second_num) << std::endl;
		} else if (operator_sign == '*') {
			std::cout << "Product: " << calc.Multiply(first_num, second_num) << std::endl;
		} else if (operator_sign == '/') {
			std::cout << "Quotient: " << calc.Divide(first_num, second_num) << std::endl;
		} else if (operator_sign == 'e') {
			std::cout << "Exited" << std::endl;
			break;
		} else {
			std::cout << "Invalid operator entered" << std::endl;
		}

		std::cout << "Enter your first number: " << std::endl;
		first_num = getIntInput();

		std::cout << "Enter your second number: " << std::endl;
		second_num = getIntInput();

		std::cout << "Enter an operator (+,-,*,/,e(exit))" << std::endl;
		std::cin >> operator_sign;
	}
	return 0;
}
