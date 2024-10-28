/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:31 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/28 16:03:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

// Class declaration
class Brain {

	private:
		std::string ideas[100];
		int nbIdeas;
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &rhs);
		~Brain();

		int getNbIdeas();
		std::string getIdeas(int i);
		void addIdea(std::string idea);
};

#endif // BRAIN_HPP
