/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:57:41 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/09 17:13:24 by Gfinet           ###   ########.fr       */
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
       Contact()
	   {
		first_name = "";
		last_name = "";
		nick_name = "";
		phone_number = "";
		dark_secret = "";
	   };

        /* Destructor */
        ~Contact(){};

        /* Copy constructor */
		Contact(const Contact &other)
		{
			this->set_first_name(other.first_name);
			this->set_last_name(other.last_name);
			this->set_nick_name(other.nick_name);
			this->set_phone_number(other.phone_number);
			this->set_dark_secret(other.dark_secret);
		};
		
		Contact& operator=(const Contact &other)
		{
			this->first_name = other.first_name; 
			this->last_name = other.last_name; 
			this->nick_name = other.nick_name; 
			this->phone_number = other.phone_number; 
			this->dark_secret = other.dark_secret; 
			return *this;
		};

        /* Operation overload = */
		//bool operator&(const ){};

		void set_first_name(const std::string str)
		{
			this->first_name = str;
		};
		void set_last_name(const std::string str)
		{
			this->last_name = str;
		};
		void set_nick_name(const std::string str)
		{
			this->nick_name = str;
		};
		void set_phone_number(const std::string str)
		{
			this->phone_number = str;
		};
		void set_dark_secret(const std::string str)
		{
			this->dark_secret = str;
		};

		const std::string get_first_name()
		{
			return this->first_name;
		};
		const std::string get_last_name()
		{
			return this->last_name;
		};
		const std::string get_nick_name()
		{
			return this->nick_name;
		};
		const std::string get_phone_number()
		{
			return this->phone_number;
		};
		const std::string get_dark_secret()
		{
			return this->dark_secret;
		};
		const std::string get_tronc_fname()
		{
			std::string temp;
			
			temp = this->first_name.substr(0, 9);
			temp += '.';
			return temp;
		};
		std::string get_tronc_lname()
		{
			std::string temp;
			
			temp = this->last_name.substr(0, 9);
			temp += '.';
			return temp;
		};
		std::string get_tronc_nname()
		{
			std::string temp;
			
			temp = this->nick_name.substr(0, 9);
			temp += '.';
			return temp;
		};
		std::string get_tronc_phnum()
		{
			std::string temp;
			
			temp = this->phone_number.substr(0, 9);
			temp += '.';
			return temp;
		};
		std::string get_tronc_dsec()
		{
			std::string temp;
			
			temp = this->dark_secret.substr(0, 9);
			temp += '.';
			return temp;
		};

};