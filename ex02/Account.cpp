/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:34:56 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/07 18:42:20 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(void) : _accountIndex(Account::_nbAccounts), _amount(0),
							_nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	std::cout << ;
}


Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(1), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits++;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount = this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
		return (false);
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	
}


void	Account::_displayTimestamp(void)
{
	std::cout << "[] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;