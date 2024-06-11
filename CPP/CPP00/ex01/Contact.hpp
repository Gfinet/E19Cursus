/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:57:41 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/11 21:42:20 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

class Contact
{
	private:

		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string dark_secret;

    public:

        /* Constructor  */
       Contact();

        /* Destructor */
        ~Contact();

        /* Copy constructor */
		Contact(const Contact &other);
		
		Contact& operator=(const Contact &other);

        /* Operation overload = */

		void set_first_name(const std::string str);
		void set_last_name(const std::string str);
		void set_nick_name(const std::string str);
		void set_phone_number(const std::string str);
		void set_dark_secret(const std::string str);

		const std::string get_first_name();
		const std::string get_last_name();
		const std::string get_nick_name();
		const std::string get_phone_number();
		const std::string get_dark_secret();
		const std::string get_tronc_fname();
		std::string get_tronc_lname();
		std::string get_tronc_nname();
		std::string get_tronc_phnum();
		std::string get_tronc_dsec();

};