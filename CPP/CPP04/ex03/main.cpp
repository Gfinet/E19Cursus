/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:06:52 by gfinet            #+#    #+#             */
/*   Updated: 2025/02/01 17:07:28 by gfinet           ###   ########.fr       */
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
        {
            if (char1.getMateria(i))
                std::cout << char1.getMateria(i)->getType() << std::endl;
            else
                std::cout << "No Materia" << std::endl;
        }
    }
    {
        std::cout << std::endl << std::endl;
        IMateriaSource* src = new MateriaSource();
        ICharacter* me = new Character("me");
        AMateria* tmp1, *tmp2;
        ICharacter* bob = new Character("bob");
        
        tmp1 = src->createMateria("ice");
        tmp1 = src->createMateria("cure");
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        tmp1 = src->createMateria("ice");
        me->equip(tmp1);
        tmp2 = src->createMateria("cure");
        me->equip(tmp2);
        
        me->use(0, *bob);
        me->use(1, *bob);
        for (int i = 0; i<4; i++)
        {
            if (me->getMateria(i))
                std::cout << me->getMateria(i)->getType() << std::endl;
            else
                std::cout << "No Materia" << std::endl;
        }
        std::cout << std::endl;
        me->unequip(0);
        me->unequip(1);
        delete tmp1;
        delete tmp2;
        for (int i = 0; i<4; i++)
        {
            if (me->getMateria(i))
                std::cout << me->getMateria(i)->getType() << std::endl;
            else
                std::cout << "No Materia" << std::endl;
        }
        delete bob;
        delete me;
        delete src;
    }
    return 0;
}