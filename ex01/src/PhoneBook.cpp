#include "main.hpp"

//Contructor
PhoneBook::PhoneBook(){
	this->_index = 0;
	this->_quantity = 0;
}

//Setters
void PhoneBook::setContact(const Contact newContact){
	this->_index = (this->_index % MAX_CONTACTS);
	this->_contacts[_index] = newContact;
	
	if (this->_index < MAX_CONTACTS)
		this->_index++;
	if (this->_quantity < MAX_CONTACTS)
		this->_quantity++;
}

//Getters
std::string PhoneBook::formatColumn(std::string str) const{
	if(str.length() > COLUMN_WIDTH)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::searchContacts() const{
	int	index;
	int	selectedIndex = 0;
	std::string input;

	if (this->_quantity == 0){
		std::cout << "No contacts registered!\n\n";
		return ;
	}

	std::cout << "|" << std::setw(10) << "index"
		<< "|" << std::setw(10) << "FirstName"
		<< "|" << std::setw(10) << "LastName"
		<< "|" << std::setw(10) << "NickName" << "\n";

	for (index = 0; index < this->_quantity; index++){
		std::cout << "|" << std::setw(10) << index
		<< "|" << std::setw(10) << formatColumn(this->_contacts[index].getFirstName())
		<< "|" << std::setw(10) << formatColumn(this->_contacts[index].getLastName())
		<< "|" << std::setw(10) << formatColumn(this->_contacts[index].getNickName())
		<< "|\n";
	}

	std::cout << "Please select the contact index to search:\n";
	while(1){
		if (!std::getline(std::cin, input)){
			std::cout << "Exiting at your request!" << std::endl;
			break;
		}
		if (input.empty()){
			std::cout << "Please enter a contact index:\n";
		}
	
		else if (input.length() != 1 || !isdigit(input[0])){
			std::cout << "Please select a valid contact index:\n";
		}
	
		else if (isdigit(input[0])){
			selectedIndex = input[0] - 48;
			if (selectedIndex < 0 || selectedIndex >= this->_quantity){
				std::cout << "Please select an existing contact index!\n";
			}
			else {
				selectedIndex = input[0] - 48;
				std::cout << "First name: " << this->_contacts[selectedIndex].getFirstName()
			<< "\n" << "Last name: " << this->_contacts[selectedIndex].getLastName()
			<< "\n" << "Nick name: " << this->_contacts[selectedIndex].getNickName()
			<< "\n" << "Phone Number: " << this->_contacts[selectedIndex].getPhoneNumber()
			<< "\n" << "Darkest Secret: " << this->_contacts[selectedIndex].getDarkestSecret()
			<< "\n\n";
			return ;
			}
		}
	}
}
