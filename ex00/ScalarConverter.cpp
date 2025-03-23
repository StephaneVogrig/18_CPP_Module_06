/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:25:01 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/23 22:09:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter & toCopy)
{
	*this = toCopy;
}

ScalarConverter::~ScalarConverter(void)
{}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & toAssign)
{
	if (this == &toAssign)
		return *this;
	return *this;
}

void ScalarConverter::convert(const std::string & literal)
{
	std::cout << "char: " << literal << std::endl;
	std::cout << "int: " << literal << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << literal << std::endl;
}
