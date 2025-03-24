/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:39:36 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/24 02:26:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include <climits>
# include <cfloat>

class ScalarConverter
{
	public:

		static void convert(const std::string & str);

	private:

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter & toCopy);

		~ScalarConverter(void);

		ScalarConverter & operator = (const ScalarConverter & toAssign);

};

#endif
