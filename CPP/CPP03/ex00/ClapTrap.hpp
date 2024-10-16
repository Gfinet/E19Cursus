/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:14:26 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/16 19:47:35 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string Name;
		int Health;
		int Energy;
		int Attack;

	public:

		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();
		ClapTrap &operator=( ClapTrap const & rhs );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string get_Name();
		int get_Health();
		int get_Energy();
		int get_Attack();
};
#endif