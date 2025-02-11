/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:13:53 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/11 20:58:09 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main()
{
    Data x;
    uintptr_t ptr;
    Data *res;

    x.x = 5;
    x.c = 'c';

    ptr = Serializer::serialize(&x);
    res = Serializer::deserialize(ptr);
    std::cout << res->x << " " << res->c << std::endl;
    return 0;
}