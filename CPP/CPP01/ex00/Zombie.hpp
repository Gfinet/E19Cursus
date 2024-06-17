/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:57:41 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 14:59:59 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

class Zombie
{
	private:

		std::string name;

    public:

        /* Constructor  */
       Zombie();
       Zombie(std::string name);

        /* Destructor */
        ~Zombie();

        /* Copy constructor */
		Zombie(const Zombie &other);
		
		Zombie& operator=(const Zombie &other);

        /* Operation overload = */
		void announce(void);
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );