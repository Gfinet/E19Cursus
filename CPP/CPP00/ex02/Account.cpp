/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:33:48 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/13 18:46:16 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << Account::getNbAccounts() << ";amount:";
	std::cout << "0" << ";created" << std::endl;
	Account::_nbAccounts++;
	_accountIndex = 0;
	_amount = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout << " index:" << getNbAccounts() << ";amount:";
	std::cout << initial_deposit << ";created" << std::endl;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbWithdrawals = 0;
}
Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
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

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:"<< Account::getNbAccounts() << ";";
	std::cout << "total:"<< Account::getTotalAmount() << ";";
	std::cout << "deposits:"<< Account::getNbDeposits() << ";";
	std::cout << "withdrawals:"<< Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";";
	std::cout << "p_amount:"<< _amount << ";";
	std::cout << "deposit:"<< deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:"<< _amount << ";";
	std::cout << "nb_deposits:"<< _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";";
	std::cout << "p_amount:"<< _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << "\n";
		return (0);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << "amount:"<< _amount << ";";
	std::cout << "nb_withdrawals:"<< _nbWithdrawals << "\n";
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (1);
}

int Account::checkAmount(void) const
{
	return _totalAmount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:";
	std::cout << _amount << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	// std::time_t time = std::time(0);

	// std::cout << "[" << time << "]";
	std::cout << "[" << "19920104_091532" << "]";
}