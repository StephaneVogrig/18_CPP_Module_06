/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:39:36 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/06 23:50:42 by svogrig          ###   ########.fr       */
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
		return 1;
	int max_significant = std::numeric_limits<valueType>::digits10 + 1;
	int int_part = static_cast<int>(value);
	int nbr_significant = 0;

	if (int_part != 0)
	{
		std::ostringstream oss;
		oss << int_part;
		nbr_significant = oss.str().length();
	}

	valueType decimal_part = std::abs(std::fmod(value, 1.0));
	int nbr_decimal = 0;
	int precision = 0;
	while (decimal_part != 0.0 && nbr_significant <= max_significant)
	{
		nbr_decimal++;
		if (nbr_significant != 0)
			nbr_significant++;
		decimal_part *= 10;
		int_part = static_cast<int>(decimal_part);
		if (int_part)
			break ;
	}

	if (nbr_significant > nbr_decimal)
		precision = max_significant - (nbr_significant - nbr_decimal);
	else
		precision = nbr_decimal + max_significant;
	if (precision == 0)
		precision = 1;
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << value;
	std::string str = oss.str();
	std::string::iterator it = str.end() - 1;

	while (*it == '0')
	{
		--precision;
		--it;
	}

	return precision <= 0 ? 1 : precision;
}

template <typename valueType>
void printChar(valueType value)
{
	if (value >= 32 && value < 128)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (is_nan(value) || value < 0 || value >= 129)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

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
		static void printConvertImpossible();

};

#endif
