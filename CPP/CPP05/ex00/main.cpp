/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:05 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/27 18:22:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("Jean", 1), b("Jacques", 0), c("Bob", 150), d("Marie", 151);

    std::cout << a.getGrade() << std::endl;
    std::cout << b.getGrade() << std::endl;
    std::cout << c.getGrade() << std::endl;
    std::cout << d.getGrade() << std::endl;
    return 0;
}