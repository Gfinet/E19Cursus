/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:46:41 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/15 18:16:41 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
//# include "Array.tpp"

template <class T> 
class Array
{
private:
	T *_lst;
	unsigned int _len;
public:
	Array();
	Array(const Array<T> &x);
	Array(unsigned int x);
	~Array();

	Array<T> operator=(const Array<T> &x);

	T& operator[](const unsigned int x) const;
	unsigned int size() const;
};

template <class T> Array<T>::Array()
{
	this->_lst = new T[0];
	std::cout << this->_lst << std::endl;
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
	if (this != &x)
	{
		if (_len != 0)
			delete[] _lst;
		_lst = new T[x._len];
		for (size_t i=0; i < x._len; i++)
			_lst[i] = x[i];
		_len = x._len;
	}
	return *this;
}

template <typename T> 
T& Array<T>::operator[](const unsigned int x) const
{
	try
	{
		if (x > _len)
			throw std::out_of_range("Exception : Out of range");
		return this->_lst[x];
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return _lst[0];
}

template <typename T> 
Array<T>::~Array()
{
	delete[] _lst;
}

template <class T> unsigned int Array<T>::size() const
{
	return _len;
}

#endif