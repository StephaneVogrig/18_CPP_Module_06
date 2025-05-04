/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:39:36 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/05 01:02:14 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include <sstream>
# include <climits>
# include <cerrno>
# include <cfloat>
# include <cmath>
# include <limits>

# define BASE_10 10

template <typename valueType>
bool is_nan(valueType value)
{
	return value != value;
}

template <typename valueType>
bool is_inf(valueType value)
{
	return value == value + 1;
}

template <typename valueType>
int nbrDecimal(valueType value)
{
	if (is_nan(value) || is_inf(value))
		return 0;
	valueType decimal_part = std::abs(std::fmod(value, static_cast<valueType>(1.0)));
	int nbr_decimal = 0;
	int precision = 0;
	int nbr_zero_at_end = 0;
	while (decimal_part != static_cast<valueType>(0.0) && precision <= std::numeric_limits<valueType>::digits10)
	{
		decimal_part *= static_cast<valueType>(10);
		int int_part = static_cast<int>(decimal_part);
		if (precision != 0 || int_part != 0)
			precision++;
		if (int_part != 0)
			nbr_zero_at_end = 0;
		else
			nbr_zero_at_end++;
		decimal_part = std::fmod(decimal_part, static_cast<valueType>(1.0));
		nbr_decimal++;
	}
	nbr_decimal -= nbr_zero_at_end;
	std::cout << "nbr_decimal: " << nbr_decimal << std::endl;
	return nbr_decimal;
};

template <typename valueType>
void printChar(valueType value)
{
	if (value >= static_cast<valueType>(32) && value < static_cast<valueType>(128))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (is_nan(value) || value < static_cast<valueType>(0) || value >= static_cast<valueType>(129))
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
};

template <typename valueType>
void printInt(valueType value)
{
	if (value >= static_cast<valueType>(INT_MIN) && value <= static_cast<valueType>(INT_MAX))
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
};


class ScalarConverter
{
	public:

		static void convert(const std::string & str);

	private:

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter & toCopy);
		~ScalarConverter(void);
		ScalarConverter & operator = (const ScalarConverter & toAssign);

		static bool isChar(const std::string & str);
		static bool isInt(const std::string & str);
		static bool isFloat(const std::string & str);
		static bool isDouble(const std::string & str);

		static void convertFromChar(const std::string & str);
		static void convertFromInt(const std::string & str);
		static void convertFromFloat(const std::string & str);
		static void convertFromDouble(const std::string & str);

		static void printFloat(float value);
		static void printDouble(double value);

};

#endif
