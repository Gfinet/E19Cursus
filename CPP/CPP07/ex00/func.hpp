/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:11:52 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/14 20:27:58 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_HPP
# define FUNC_HPP


template <typename T> void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T> T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

#endif