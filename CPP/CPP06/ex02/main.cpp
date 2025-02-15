/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:46:34 by Gfinet            #+#    #+#             */
/*   Updated: 2025/02/13 17:06:49 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"

int main()
{
	Base *base;
	base = generate();
	identify(base);

	C c;
	Base &ref(c);
	identify(ref);
	(void)ref;
	delete base;
	return 0;
}