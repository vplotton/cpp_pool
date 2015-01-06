/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 15:39:35 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 18:54:44 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit)
{
	std::cout << "index:"
		<< _totalAmount
		<< ";amount:"
		<< initial_deposit
		<< ";created"
		<< std::endl;

	_totalAmount += _amount;
}

Account::Account()
{
	_nbAccounts++;
}

Account::~Account()
{
	std::cout << "index:"
		<< _nbAccounts
		<< ";amount:"
		<< _amount
		<< ";closed"
		<< std::endl;

	_nbAccounts--;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int    Account::getTotalAmount()
{
	return (_totalAmount);
}

int    Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int    Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}


void	Account::displayAccountsInfos()
{
	std::cout << "accounts:"
		<< _nbAccounts
		<< ";total:20049"
		<< ";deposits:"
		<< _totalNbDeposits
		<< ";withdrawals:"
		<< _totalNbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	std::cout << "index:"
		<< _accountIndex
		<< ";p_amount:"
		<< _amount
		<< ";deposits:"
		<< _nbDeposits;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:"
		<< _amount
		<< ";nb_deposits:"
		<< _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout << "index:"
		<< _accountIndex
		<< ";p_amount:"
		<< _amount
		<< ";deposits:"
		<< _nbDeposits
		<< ";withdrawal:";
	if (_amount - withdrawal > 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << withdrawal
			<< ";amount:"
			<< _amount
			<< ";nb_withdrawals:"
			<< _nbWithdrawals
			<< std::endl;
	}
	else
	{
		std::cout << "refused" << std::endl;
	}
}

int		Account::checkAmount() const
{
	_amountChecked++;
	return (_amount);
}

void	Account::displayStatus() const
{
	std::cout << "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";deposits:"
		<< _nbDeposits
		<< ";withdrawals:"
		<< _nbWithdrawals
		<< std::endl;
}
