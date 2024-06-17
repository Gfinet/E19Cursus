/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:57:27 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 18:00:54 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#	define HUMAN_A_HPP
#	include <iomanip>
#	include <iostream>
#	include "Weapon.hpp"

class HumanA
{
	private:

		Weapon &weapon;
		std::string name;

    public:

        /* Constructor  */
       //HumanA(std::string name, Weapon type);
       HumanA(std::string name, Weapon& type);

        /* Destructor */
        ~HumanA();

        /* Copy constructor */
		HumanA(const HumanA &other);
		
		HumanA& operator=(const HumanA &other);

        /* Operation overload = */
		void attack();
};

#endif