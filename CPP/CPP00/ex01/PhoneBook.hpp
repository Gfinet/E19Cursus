/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:49:10 by gfinet            #+#    #+#             */
/*   Updated: 2024/08/20 18:41:18 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include "Contact.hpp"

class PhoneBook
{
	private:
		int old_cont;
		int nb_cont;
		Contact lst[8];

		void print_top_list();
		void print_contact(int i);
		void print_info(int i);
		
    public:

        /* Constructor  */
		PhoneBook();
        /* Destructor */
        ~PhoneBook();
        /* Copy constructor */
		PhoneBook(const PhoneBook &other);
		PhoneBook &operator= (const PhoneBook &other);

        
		void set_contact(Contact c, int i);
		void add(void);
		void search(void);
		void exit(void);

};

#endif