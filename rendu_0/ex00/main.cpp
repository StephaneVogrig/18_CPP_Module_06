/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:27:07 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/23 22:13:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << *argv << " <literal>" << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(argv[1]);
	return EXIT_SUCCESS;
}
