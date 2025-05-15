/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:42:58 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/07 16:12:43 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer & toCopy)
{
	(void)toCopy;
}

Serializer::~Serializer()
{}

Serializer & Serializer::operator = (const Serializer & toAssign)
{
	(void)toAssign;
	return *this;
}

uintptr_t Serializer::serialize(Data * ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
