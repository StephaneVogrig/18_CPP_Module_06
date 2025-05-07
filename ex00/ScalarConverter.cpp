/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:25:01 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/07 14:40:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* constructor ---------------------------------------------------------------*/

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter & toCopy)
{
	(void)toCopy;
}

/* destructor ----------------------------------------------------------------*/

ScalarConverter::~ScalarConverter(void)
{}

/* operator ------------------------------------------------------------------*/

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & toAssign)
{
	(void)toAssign;
	return *this;
}

void ScalarConverter::convert(const std::string & str)
{
	// subject want to not handle scientific notation
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == 'e')
		{
			printConvertImpossible();
			return ;
		}
	}
	if (isChar(str))
		convertFromChar(str);
	else if (isInt(str))
		convertFromInt(str);
	else if (isFloat(str))
		convertFromFloat(str);
	else if (isDouble(str))
		convertFromDouble(str);
	else
		printConvertImpossible();
}

bool ScalarConverter::isChar(const std::string & str)
{
	return str.length() == 1 && !isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string & str)
{
	char * endptr;
	errno = 0;
	long value = strtol(str.c_str(), &endptr, BASE_10);
	return errno == 0 && *str.begin() != '\0' && *endptr == '\0' && value >= INT_MIN && value <= INT_MAX;
}

bool ScalarConverter::isFloat(const std::string & str)
{
	if (str.empty() || *(str.end() - 1) != 'f')
		return false;
	std::string tmp = str.substr(0, str.length() - 1);
	char * endptr;
	errno = 0;
	strtof(tmp.c_str(), &endptr);
	return errno == 0 && *endptr == '\0';
}

bool ScalarConverter::isDouble(const std::string & str)
{
	if (str.empty())
		return false;
	char * endptr;
	errno = 0;
	strtod(str.c_str(), &endptr);
	return errno == 0 && *endptr == '\0';
}

void ScalarConverter::convertFromChar(const std::string & str)
{
	char value = *str.begin();
	std::cout << "char: " << value << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

void ScalarConverter::convertFromInt(const std::string & str)
{
	int value = atoi(str.c_str());
	printChar<int>(value);
	std::cout << "int: " << value << std::endl;
	printFloat(static_cast<float>(value));
	printDouble(static_cast<double>(value));
}

void ScalarConverter::convertFromFloat(const std::string & str)
{
	float value = strtof(str.c_str(), NULL);
	printChar<float>(value);

	if (value >= static_cast<float>(INT_MIN) && value < static_cast<float>(INT_MAX))
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	printFloat(value);
	printDouble(static_cast<double>(value));
}

void ScalarConverter::convertFromDouble(const std::string & str)
{
	double value = strtod(str.c_str(), NULL);
	printChar<double>(value);

	if (value > static_cast<double>(INT_MIN) - 1 && value < static_cast<double>(INT_MAX) + 1)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	printFloat(static_cast<float>(value));
	printDouble(value);
}

void ScalarConverter::printFloat(float value)
{
	int precision = nbrDecimal<float>(value);
	std::cout << std::fixed << std::setprecision(precision) << "float: " << value << 'f' << std::endl;
};

void ScalarConverter::printDouble(double value)
{
	int precision = nbrDecimal<double>(value);
	std::cout << std::fixed << std::setprecision(precision) << "double: " << value << std::endl;
};

void ScalarConverter::printConvertImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
