/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:33:21 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/08 13:05:05 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.hpp"

Base * generate(void)
{
    srand(clock());
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << 'C' << std::endl;
}

void identify(Base & p)
{
	try
	{
		A& ref = dynamic_cast<A&>(p);
		(void)ref;
		std::cout << 'A' << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B& ref = dynamic_cast<B&>(p);
		(void)ref;
		std::cout << 'B' << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C& ref = dynamic_cast<C&>(p);
		(void)ref;
		std::cout << 'C' << std::endl;
	}
	catch(const std::exception& e)
	{}
}

int main(void)
{
	Base * base = generate();

	displaySection("ex02");
	displaySubtest("identify a pointer");
	identify(base);
	displaySubtest("identify a reference");
	identify(*base);
	
	delete base;

	return EXIT_SUCCESS;
}
