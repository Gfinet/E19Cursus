/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:59:32 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 16:47:23 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iomanip>
#include <iostream>

class Weapon
{
	private:

		std::string type;

    public:

        /* Constructor  */
       Weapon();
       Weapon(std::string name);

        /* Destructor */
        ~Weapon();

        /* Copy constructor */
		Weapon(const Weapon &other);
		
		Weapon& operator=(const Weapon &other);

        /* Operation overload = */
		const std::string& getType();
		void setType(std::string name);
};
#endif