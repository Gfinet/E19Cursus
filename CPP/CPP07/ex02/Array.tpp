/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:01:27 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/15 17:47:31 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <class T> Array<T>::Array()
{
	this->_lst = new T[5];
	_len = 0;
}

template <class T> 
Array<T>::Array(unsigned int x)
{
	this->_lst = new T[x];
	_len = x;
}

template <class T> 
Array<T>::Array(const Array<T> &x)
{
	*this = x;
}

template <typename T> 
Array<T> Array<T>::operator=(const Array<T> &x)
{
	if (*this != x)
	{
		 delete[] _lst;
		 _lst = new T[x._len];
		 for (size_t i=0; i < x._len; i++)
		 	_lst[i] = x[i];
		_len = x._len;
	}
	return *this;
}

template <typename T> 
T Array<T>::operator[](const unsigned int x)
{
	try
	{
		this->lst[x];
		return this->lst[x];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T> 
Array<T>::~Array()
{
}

#endif