#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//getters
int Account::getNbAccounts( void ) {
    return ( _nbAccounts );
}

int Account::getTotalAmount( void ) {
    return( _totalAmount );
}

int Account::getNbDeposits( void ) {
    return( _totalNbDeposits );
}

int	Account::getNbWithdrawals( void ) {
    return ( _totalNbWithdrawals );
}

void Account::displayAccountsInfos( void ) {
    std::cout << "accounts:" << _nbAccounts << ";total:" 
        << _totalAmount << ";deposits:" << _totalNbDeposits 
        << ";withdrawals:" << _totalNbWithdrawals << "\n";        
}
