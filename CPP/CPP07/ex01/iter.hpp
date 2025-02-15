/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:21:41 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/14 20:36:21 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> void iter(T* array, size_t len, void (*func)(T &arg))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T> void doubleVal(T &arg)
{
	arg *= 2;
}

template <typename T> void plusOne(T &arg)
{
	arg++;
}
#endif