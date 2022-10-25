/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:34:15 by gulee             #+#    #+#             */
/*   Updated: 2022/10/25 19:12:37 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _nbWithdrawals = 0;
    _nbDeposits = 0;
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "created" << std::endl;;
}

Account::Account(void) {}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}


void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposit:" <<  deposit << ";";
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << checkAmount() << ";";
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "nb_deposits:" <<  _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "withdrawal:";
    if (checkAmount() < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    } else {
        std::cout << withdrawal << ";";
        _amount -= withdrawal;
        std::cout << "amount:" << checkAmount() << ";";
        _nbWithdrawals++;
        _totalNbWithdrawals++;
		_totalAmount -= withdrawal;
        std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }

}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" <<  _nbDeposits << ";";
    std::cout << "withdrawals:" <<  _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" <<(now->tm_year + 1900);
    std::cout << std::setfill('0') << std::setw(2) << now->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << now->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << now->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << now->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << now->tm_sec;
    std::cout << "] ";
}
