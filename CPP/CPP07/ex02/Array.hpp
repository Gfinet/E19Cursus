/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:46:41 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/18 15:57:26 by gfinet           ###   ########.fr       */
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
	unsigned int _size;
public:
	Array();
	Array(const Array<T> &x);
	Array(unsigned int x);
	~Array();

	Array<T> operator=(const Array<T> &x);

	T& operator[](const unsigned int x) const;
	unsigned int size() const;
};

template <typename T> static T* memcpy(T* orig, size_t len)
{
	T* cpy;
	
	if (!orig || !len)
		return 0;
	cpy = new T[len];
	for (size_t i = 0; i < len; i++)
		cpy[i] = orig[i];
	std::cout << "end\n" ;
	return cpy;
}

template <class T> Array<T>::Array()
{
	std::cout << "Empty constructor called\n";
	this->_lst = 0;
	std::cout << this->_lst << std::endl;
	_size = 0;
}

template <class T> 
Array<T>::Array(unsigned int x)
{
	std::cout << "constructor with " << x << " elem called\n";
	this->_lst = new T[x];
	_size = x;
}

template <class T> 
Array<T>::Array(const Array<T> &x) : _lst(new T[x._size]), _size(x._size)
{
	// std::cout << "copy constructor called\n";
	for (size_t i=0; i < x._size; i++)
		_lst[i] = x._lst[i];
}

template <typename T> 
Array<T> Array<T>::operator=(const Array<T> &x)
{
	std::cout << "Assignement operator called\n";
	if (this != &x)
	{
		delete[] _lst;
		_lst = new T[x._size];
		for (size_t i=0; i < x._size; i++)
			_lst[i] = x._lst[i];
		_size = x._size;
	}
	return *this;
}

template <typename T> 
T& Array<T>::operator[](const unsigned int x) const
{
	try
	{
		if (x >= _size)
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
	return _size;
}

#endif