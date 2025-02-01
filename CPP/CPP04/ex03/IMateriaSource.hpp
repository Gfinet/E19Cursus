/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:32:37 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 16:44:30 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{

	protected:
		AMateria* _stock[4];
		unsigned int _nbMat;
	
	public:
		IMateriaSource();
		IMateriaSource( IMateriaSource const & src );
		virtual IMateriaSource &operator=( IMateriaSource const & rhs );
		
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;



};

#endif /* ************************************************** IMATERIASOURCE_H */