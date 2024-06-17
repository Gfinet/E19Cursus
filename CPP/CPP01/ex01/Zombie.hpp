/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:20:57 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 15:28:38 by Gfinet           ###   ########.fr       */
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

Zombie* zombieHorde(int N, std::string name);