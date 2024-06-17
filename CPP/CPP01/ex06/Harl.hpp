/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:48:10 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 23:52:02 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

class Harl
{
	private:

		void debug();
		void info();
		void warning();
		void error();

    public:

        /* Constructor  */
       Harl();

        /* Destructor */
        ~Harl();

        /* Operation overload = */
		void complain(std::string level);
		typedef void (Harl::*ptr)(void);
};