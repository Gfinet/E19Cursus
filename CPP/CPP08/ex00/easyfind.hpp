/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:03:48 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/18 17:53:48 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <vector>

template <typename T> int easyfind( T &cont, int val)
{
    typename T::iterator it;
    while (it != cont.end())
    {
        if (*it == val)
            return 1;
        it++;
    }
    return 0;
}