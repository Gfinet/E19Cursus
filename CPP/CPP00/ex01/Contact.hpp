/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:57:41 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/07 16:36:11 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class Contact
{
	private:

		char *first_name;
		char *last_name;
		char *nick_name;
		char *phone_number;
		char *dark_secret;

    public:

        /* Constructor  */
       Contact();

        /* Destructor */
        ~Contact();

        /* Copy constructor */
		Contact(const Contact &cpy);
		Contact& operator=(const Contact &cpy);

        /* Operation overload = */
		bool operator&(const ){};

		void set_first_name(char *str)
		{
			this->first_name = str;
		};
		void set_last_name(char *str)
		{
			this->first_name = str;
		};
		void set_nick_name(char *str)
		{
			this->first_name = str;
		};
		void set_phone_number(char *str)
		{
			this->first_name = str;
		};
		void set_dark_secret(char *str)
		{
			this->first_name = str;
		};

		char *get_first_name(char *str)
		{
			return this->first_name;
		};
		char *get_last_name(char *str)
		{
			return this->last_name;
		};
		char *get_nick_name(char *str)
		{
			return this->nick_name;
		};
		char *get_phone_number(char *str)
		{
			return this->phone_number;
		};
		char *get_dark_secret(char *str)
		{
			return this->phone_number;
		};
};