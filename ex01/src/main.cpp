#include "main.hpp"

int main(int argc, char **argv){
    (void) argc;
    (void) argv;
    Contact newContact;
    PhoneBook myPhoneBook;
    std::string input;

	
	while (1){
		std::cout << "Please enter your command:\n\"ADD\":to"
			" add a new contact\n\"SEARCH\":to search for a contact"
			"\n\"EXIT\":to exit your PhoneBook\n";
		std::getline(std::cin, input);

        if (input == "ADD"){
            std::cout << "Please insert First Name:\n";    
			std::getline(std::cin, input);
        	while (input.empty()){
            	std::cout << "Please insert First Name:\n";    
				std::getline(std::cin, input);
			}
			newContact.setFirstName(input);

			std::cout << "Please insert Last Name:\n";    
			std::getline(std::cin, input);
        	while (input.empty()){
            	std::cout << "Please insert Last Name:\n";    
				std::getline(std::cin, input);
			}
			newContact.setLastName(input);

			std::cout << "Please insert Nick Name:\n";    
			std::getline(std::cin, input);
        	while (input.empty()){
            	std::cout << "Please insert Nick Name:\n";    
				std::getline(std::cin, input);
			}
			newContact.setNickName(input);

			
			std::cout << "Please insert Phone Number:\n";    
			while (true){
				std::getline(std::cin, input);
				
				if (input.empty()){
					std::cout << "Input cannot be empty. Please insert Phone Number:\n";
					continue;
				}
				
				bool isValid = true;
				for (size_t i = 0; i < input.length(); i++){
					if (!isdigit(input[i])){
						isValid = false;
						std::cout << "Invalid characters! Please insert a valid Phone Number:\n";
						break;
					}
				}
				if (isValid)
					break;
			}
			newContact.setPhoneNumber(input);

			std::cout << "Please insert Darkest Secret:\n";    
			std::getline(std::cin, input);
        	while (input.empty()){
            	std::cout << "Please insert Darkest Secret:\n";    
				std::getline(std::cin, input);
			}
			newContact.setDarkestSecret(input);

			myPhoneBook.setContact(newContact);
			
			std::cout << "New contact added!\n\n";
        }
    
        else if (input == "SEARCH"){
        	myPhoneBook.searchContacts();
		}
    
        else if (input == "EXIT"){
            return (0);
        }
        else
            std::cout << "Please enter a valid command!\n\n";    
    }
    return (0);
}
