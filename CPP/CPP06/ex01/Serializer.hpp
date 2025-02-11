/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:13:47 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/11 20:57:25 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct t_data
{
	int		x;
	char	c;
} Data;

class Serializer
{

	public:

		Serializer();
		Serializer( Serializer const & src );
		virtual ~Serializer() = 0;

		Serializer &		operator=( Serializer const & rhs );
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);


	private:

};

#endif /* ****************************************************** SERIALIZER_H */