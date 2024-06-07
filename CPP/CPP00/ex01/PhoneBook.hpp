/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:49:10 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/07 16:34:59 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int old_cont;
		Contact lst[8];

    public:

        /* Constructor  */
       PhoneBook()
	   {
			this->old_cont = 0;
	   };

        /* Destructor */
        ~PhoneBook();

        /* Copy constructor */
		PhoneBook(const PhoneBook &cpy);
		PhoneBook &operator = (const PhoneBook &cpy);

        /* Operation overload = */

		void add(void)
		{
			int i = 0;
			char *str;
			Contact *new_cont = new Contact;

			std::cout << "What's the first name?" << std::endl; 
			std::cin >> str;
			new_cont->set_first_name(str);
			std::cout << "What's the last name?" << std::endl; 
			std::cin >> str;
			new_cont->set_last_name(str);
			std::cout << "What's the nickname?" << std::endl; 
			std::cin >> str;
			new_cont->set_nick_name(str);
			std::cout << "What's the number?" << std::endl; 
			std::cin >> str;
			new_cont->set_phone_number(str);
			std::cout << "What's the dark secret?" << std::endl; 
			std::cin >> str;
			new_cont->set_dark_secret(str);
			while ( i < 8 & this->lst[i])
				i++;
			if (i == 8)
			{
				lst[old_cont] = *new_cont;
				old_cont++;
				old_cont *= (old_cont != 8);
			}
			else
				lst[i] = *new_cont;
		};
		void search(void){};
		void exit(void){}

};

#endif