/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:57:21 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 18:01:22 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
#include <iomanip>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:

		Weapon *weapon;
		std::string name;

    public:

        /* Constructor  */
       HumanB();
       HumanB(std::string name);

        /* Destructor */
        ~HumanB();

        /* Copy constructor */
		HumanB(const HumanB &other);
		
		HumanB& operator=(const HumanB &other);

        /* Operation overload = */
		void attack();
		void setWeapon(Weapon &type);
};

#endif