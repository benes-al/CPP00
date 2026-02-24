#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor

Account::Account(int initial_deposit) : _amount(initial_deposit) {
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _displayTimestamp();
    
    std::cout   << "index:"  << _accountIndex 
    << ";amount:" << initial_deposit 
    << ";created" << std::endl;
}

// Static Method

void    Account::_displayTimestamp( void ) {
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);

    char buffer[20];
    
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime); 
    
    std::cout << buffer; 
}

void Account::displayAccountsInfos( void ) {
    std::cout   << "accounts:" << _nbAccounts 
                << ";total:" << _totalAmount 
                << ";deposits:" << _totalNbDeposits 
                << ";withdrawals:" << _totalNbWithdrawals << std::endl;        
}

// Setters

void Account::makeDeposit(int deposit) {
    _totalAmount += deposit;
    

}

bool Account::makeWithdrawal(int withdrawal) {
    
}

int  Account::checkAmount(void) const {
    
}

//Getters

void Account::displayStatus(void) const { 

}

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


// Destructor
Account::~Account(void) {
    
}


