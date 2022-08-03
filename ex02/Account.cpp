#include "Account.hpp"
#include <iostream>
#include <string>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(void) 
{
    _accountIndex = _nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
            << ";amount:" << _amount 
            << ";created" << std::endl;

}

Account::Account(int deposit) 
{
  _accountIndex = _nbAccounts;
  _nbAccounts++;
  _amount = deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _totalAmount += deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex 
			<< ";amount:" << _amount
            << ";created\n";
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
	<< ";amount:" << _amount 
	<< ";closed" << std::endl;
}

int	Account::getNbAccounts(void) { return _nbAccounts; }
int	Account::getTotalAmount(void) { return _totalAmount; }
int	Account::getNbDeposits(void) { return _totalNbDeposits; }
int	Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::_displayTimestamp(void) 
{
    time_t t;
    time(&t);
    char buf[1024];
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localtime(&t));
    std::cout << buf;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	const	int p_amount = _amount;
    if (deposit <= 0)
        return ;
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			<< ";p_amount:" << p_amount
			<< ";deposit:" << deposit 
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) 
{
    int changedAmount = _amount - withdrawal;
    if (changedAmount < 0)
    {
        {
            _displayTimestamp();
            std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount 
			<< ";withdrawal:refused" 
			<< std::endl;
        }
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
	_displayTimestamp();
    std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << withdrawal 
			<< ";amount:" << changedAmount
			<< ";nb_withdrawals:" << _nbWithdrawals 
			<< std::endl;
    _amount = changedAmount;
    return true;
}
