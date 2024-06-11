/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:33:48 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/11 22:24:35 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _nbAccounts << ";amount:";
	std::cout << "0" << ";created" << std::endl;
	_nbAccounts++;
	_accountIndex = 0;
	_amount = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _nbAccounts << ";amount:";
	std::cout << initial_deposit << ";created" << std::endl;
	_nbAccounts++;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbWithdrawals = 0;
}

Account::~Account(void)
{

}

int Account::getNbAccounts()
{
	return _nbAccounts;
}
int Account::getTotalAmount()
{
	return _totalAmount;
}
int Account::getNbDeposits()
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::makeDeposit(int deposit)
{

}

bool Account::makeWithdrawal(int withdrawal)
{

}

int Account::checkAmount(void) const
{
	return _totalAmount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " account:" << _nbAccounts << ";amount:";
	std::cout << _totalAmount << ";deposit:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t time;
	int min, hour, day, year;
	std::cout << std::asctime(std::localtime(&time))
              << time << " seconds since the Epoch\n";
}