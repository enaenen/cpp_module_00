#include "Account.hpp"
#include <iostream>
#include <string>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(void) {}

Account::Account(int deposit) {
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
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount 
		<< ";closed" << std::endl;
    }
}

int	Account::getNbAccounts(void) { return _nbAccounts; }
int	Account::getTotalAmount(void) { return _totalAmount; }
int	Account::getNbDeposits(void) { return _totalNbDeposits; }
int	Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::_displayTimestamp(void) {
    // std::cout << "[19920104_091532] ";
    std::time_t t;
    std::time(&t);
    char buf[1024];
    std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", std::localtime(&t));
    std::cout << buf;
}

void Account::makeDeposit(int deposit)
{
	const int p_amount = _amount;
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

bool	Account::makeWithdrawal(int withdrawal){

}

int		Account::checkAmount( void ) const{

}

void	Account::displayStatus( void ) const{
	
}