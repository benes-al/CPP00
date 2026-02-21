#include "main.hpp"

//Contructor
PhoneBook::PhoneBook(){
	this->_index = 0;
	this->_quantity = 0;
}

//Setters
void PhoneBook::setContact(const Contact newContact){
	//_index = (_index % MAX_CONTACTS);
	_contacts[_index] = newContact;
	
	while(_index < MAX_CONTACTS)
		_index++;
	while (_quantity <= MAX_CONTACTS)
		_quantity++;
}

//Getters
std::string PhoneBook::formatColumn(std::string str) const{
	if(str.length() > COLUMN_WIDTH)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::searchContacts() const{
	int	index;
	
	for (index = 0; index < _quantity; index++){
		std::cout << "|" << std::setw(10) << index
		<< "|" << std::setw(10) << formatColumn(_contacts[index].getFirstName())
		<< "|" << std::setw(10) << formatColumn(_contacts[index].getLastName())
		<< "|" << std::setw(10) << formatColumn(_contacts[index].getNickName())
		<< "|\n";
	}
}

