/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:25:01 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/24 02:57:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* constructor ---------------------------------------------------------------*/

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter & toCopy)
{
	*this = toCopy;
}

/* destructor ----------------------------------------------------------------*/

ScalarConverter::~ScalarConverter(void)
{}

/* operator ------------------------------------------------------------------*/

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & toAssign)
{
	if (this == &toAssign)
		return *this;
	return *this;
}

/* utilities -----------------------------------------------------------------*/

/*
	Checking for NaN bit patterns in C++
	https://codereview.stackexchange.com/questions/272093/checking-for-nan-bit-patterns-in-c
	A double (IEEE 754) is a nan if:
	- all bits  of exposant are 1
	- mantisse is not 0

*/
static bool isNan(double d)
{
	union U {unsigned long long ui64; double f64;} x;
	x.f64 = d;
	return (x.ui64 & 0x7FFFFFFFFFFFFFFFu) >= 0x7FF0000000000001u;
}

static bool isChar(const std::string & literal)
{
	if (literal.length() != 1)
		return false;
	if (literal[0] < 32 || literal[0] > 126)
		return false;
	if (isdigit(literal[0]))
		return false;
	return true;
}

static bool isInvalidLiteral(const std::string & literal, char * endptr)
{
	if (endptr == literal.c_str())
		return true;

	const char * endstr = literal.c_str() + literal.length() - 1;
	if (endptr == endstr && *endptr == 'f')
		return false;

	if (*endptr != '\0')
		return true;

	return false;
}

void ScalarConverter::convert(const std::string & literal)
{
	char * endptr = NULL;
	double d;
	if (isChar(literal))
		d = static_cast<double>(literal[0]);
	else
	{
		d = strtod(literal.c_str(), &endptr);
		if (isInvalidLiteral(literal, endptr))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}

	/* display in char */
	std::cout << "char: ";
	if ((d >= 0 && d < 32) || d == 127)
		std::cout << "Non displayable" << std::endl;
	else if (d > 31 && d < 127)
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	/* display in int */
	std::cout << "int: ";
	if (d > INT_MAX || d < INT_MIN || isNan(d))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	/* display in float */
	std::cout << "float: ";
	std::cout  << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(d) << "f" << std::endl;

	/* display in float */
	std::cout << "double: " << d << std::endl;

}
