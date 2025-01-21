/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:06:52 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/21 17:23:41 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
    Ice ice1;
    Cure cure1;
    std::string Name1("Bob"), Name2("Jeff");
    Character char1(Name1), char2(Name2);

    char1.equip(ice1.clone());
    char1.equip(cure1.clone());
    
    char1.use(0, char2);
    char1.use(1, char2);
    char1.use(2, char2);
    char1.use(3, char2);
    
    for (int i = 0; i<4; i++)
        if (char1.getMateria(i))
            std::cout << char1.getMateria(i)->getType() << std::endl;
        else
            std::cout << "No Materia" << std::endl;
    }
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
        return 0;
    }
    return 0;
}