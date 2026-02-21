#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <iomanip>

#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10

class PhoneBook{
private:
    Contact _contacts[MAX_CONTACTS];
    int     _quantity;
	int		_index;

public:
    //Setters
    void setContact(const Contact newContact);
	
    //Getters
	std::string formatColumn(std::string str) const;
	void searchContacts() const;

	//Constructor
	PhoneBook();
};	

#endif