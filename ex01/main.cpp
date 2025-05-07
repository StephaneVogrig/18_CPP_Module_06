/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:44:20 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/07 16:45:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Serializer.hpp"
#include "utils.hpp"

int main()
{
	displaySection("Serializer");

	Data data;
	std::cout << "Data adress: " << &data << std::endl;

	uintptr_t uiptr = Serializer::serialize(&data);
	std::cout << "uiptr      : " << uiptr << std::endl;
	std::cout << std::hex << "uiptr hexa : " << uiptr << std::endl;

	Data * dataPtr = Serializer::deserialize(uiptr);
	std::cout << "dataptr    : " << dataPtr << std::endl;

	if (dataPtr == &data)
		std::cout << YELLOW "the program work fine" RESET << std::endl;
	else
		std::cout << RED "the program work wrong" RESET << std::endl;

	return EXIT_SUCCESS;
}
