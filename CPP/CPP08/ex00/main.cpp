/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:03:20 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/18 18:41:54 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

static void addIntToCont(std::vector<int> &cont, int *p, size_t len)
{
    cont.clear();
    for (size_t i = 0; i< len; i++)
        cont.push_back(p[i]);
}

static void printContent(const std::vector<int> &cont)
{
    std::vector<int>::const_iterator it = cont.begin();
    while (it != cont.end())
    {
        std::cout << *it << " " << std::endl;
        it++;
    }
}

int main()
{
    std::vector<int> vec;
    int tab[6] = {1,2,3,4,5,6}, tab2[2] = {7,8};

    addIntToCont(vec, tab, 6);
    printContent(vec);
    addIntToCont(vec, tab2, 2);
    std::cout << "dhsafgakjhsd\n" ;
    easyfind(vec, 3);
    std::cout << easyfind(vec, 3) << std::endl;

    std::cout << easyfind(vec, -5) << std::endl;

    return 0;
}