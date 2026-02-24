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
    
    std::cout   << "index:" << _accountIndex 
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
    _displayTimestamp();

    std::cout   << "accounts:" << _nbAccounts 
                << ";total:" << _totalAmount 
                << ";deposits:" << _totalNbDeposits 
                << ";withdrawals:" << _totalNbWithdrawals << std::endl;        
}

//Methods

void Account::displayStatus(void) const { 
    _displayTimestamp();
    
    std::cout   << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals
                << std::endl;
}

// Setters

void Account::makeDeposit(int deposit) {
    _displayTimestamp();

    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    
    std::cout   << "index:" << _accountIndex
                << ";p_amount:" << p_amount
                << ";deposit:" << deposit
                << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits
                << std::endl; 

    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    bool approved = true;
    int amount = _amount - withdrawal;

    if (amount < 0){
        approved = false;
    }

    _displayTimestamp();
    
    std::cout   << "index:" << _accountIndex
                << ";p_amount:" << _amount;

    if (!approved){
        std::cout   << ";withdrawal:refused"
                    << std::endl;
        return approved;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    std::cout   << ";withdrawal:" << withdrawal
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals
                << std::endl; 
    return approved;
}

int  Account::checkAmount(void) const {
    return _amount ;
}

//Getters

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}


// Destructor
Account::~Account(void) {
    _displayTimestamp();
    
    std::cout   << "index:" << _accountIndex 
                << ";amount:" << _amount 
                << ";closed" << std::endl;
    
    _nbAccounts--;
    _totalAmount -= _amount;
}