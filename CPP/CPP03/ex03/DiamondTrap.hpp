/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:18 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/22 14:59:30 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
	private :
		std::string Name;
		
	public:

		DiamondTrap();
		DiamondTrap(std::string Name);
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();
		DiamondTrap &operator=( DiamondTrap const & rhs );

		void whoAmI();
};
#endif
