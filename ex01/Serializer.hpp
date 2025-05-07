/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:43:06 by svogrig           #+#    #+#             */
/*   Updated: 2025/05/07 16:44:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public:

		static uintptr_t serialize(Data * ptr);
		static Data * deserialize(uintptr_t raw);

	private:

		Serializer();
		Serializer(const Serializer & toCopy);
		~Serializer();
		Serializer & operator = (const Serializer & toAssign);

};

#endif
