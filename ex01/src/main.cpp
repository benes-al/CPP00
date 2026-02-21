#include "main.hpp"

int main(int argc, char **argv){
    (void) argc;
    (void) argv;
    Contact newContact;
    PhoneBook myPhoneBook;
    std::string input;

    std::cout << "Please enter your command:\n\"ADD\":to"
        "add a new contact\n\"SEARCH\":to search for a contact"
        "\n\"EXIT\":to exit your PhoneBook\n";

	while (1){
        std::getline(std::cin, input);

        if (input == "ADD"){
            std::cout << "Please insert First Name:\n";    
			std::getline(std::cin, input);
        	while(input.empty()){
            	std::cout << "Please insert First Name:\n";    
				std::getline(std::cin, input);
			}
			newContact.setFirstName(input);

			std::cout << "Please insert Last Name:\n";    
			std::getline(std::cin, input);
        	while(input.empty()){
            	std::cout << "Please insert Last Name:\n";    
				std::getline(std::cin, input);
			}
			newContact.setLastName(input);

			std::cout << "Please insert Nick Name:\n";    
			std::getline(std::cin, input);
        	while(input.empty()){
            	std::cout << "Please insert Nick Name:\n";    
				std::getline(std::cin, input);
			}
			newContact.setNickName(input);

			std::cout << "Please insert Phone Number:\n";    
			std::getline(std::cin, input);
        	while(input.empty()){
            	std::cout << "Please insert Phone Number:\n";    
				std::getline(std::cin, input);
			}
			newContact.setPhoneNumber(input);

			std::cout << "Please insert Darkest Secret:\n";    
			std::getline(std::cin, input);
        	while(input.empty()){
            	std::cout << "Please insert Darkest Secret:\n";    
				std::getline(std::cin, input);
			}
			newContact.setDarkestSecret(input);
			myPhoneBook.setContact(newContact);
			std::cout << "New contact added!\n\nPlease enter your " 
				"command:\n\"ADD\":to add a new contact\n\"SEARCH"
				"\":to search for a contact\n\"EXIT\":to exit your"
				" PhoneBook\n";    
        }
    
        else if (input == "SEARCH"){
        	myPhoneBook.searchContacts();
		}
    
        else if (input == "EXIT"){
            return (0);
        }
        else
            std::cout << "Please enter a valid command\n";    
    }
    return (0);
}
