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
		if (!std::getline(std::cin, input)){
			std::cout << "Exiting at your request!" << std::endl;
			break;
		}

        if (input == "ADD"){
            std::cout << "Please insert First Name:\n";    
			
			if (!std::getline(std::cin, input)){
				std::cout << "Exiting at your request!" << std::endl;
				break;
			}

        	while (input.empty()){
            	std::cout << "Please insert First Name:\n";    
				if (!std::getline(std::cin, input)){
					std::cout << "Exiting at your request!" << std::endl;
					break;
				}
			}
			newContact.setFirstName(input);

			std::cout << "Please insert Last Name:\n";    
			if (!std::getline(std::cin, input)){
				std::cout << "Exiting at your request!" << std::endl;
				break;
			}
        	while (input.empty()){
            	std::cout << "Please insert Last Name:\n";    
				if (!std::getline(std::cin, input)){
					std::cout << "Exiting at your request!" << std::endl;
					break;
				}
			}
			newContact.setLastName(input);

			std::cout << "Please insert Nick Name:\n";    
			if (!std::getline(std::cin, input)){
				std::cout << "Exiting at your request!" << std::endl;
				break;
			}
        	while (input.empty()){
            	std::cout << "Please insert Nick Name:\n";    
				if (!std::getline(std::cin, input)){
					std::cout << "Exiting at your request!" << std::endl;
					break;
				}
			}
			newContact.setNickName(input);

			
			std::cout << "Please insert Phone Number:\n";    
			bool isValid = false;
			while (!isValid){
				if (!std::getline(std::cin, input)){
					std::cout << "Exiting at your request!" << std::endl;
					break;
				}
				
				if (input.empty()){
					std::cout << "Input cannot be empty. Please insert Phone Number:\n";
					continue;
				}
				
				isValid = true;
				for (size_t i = 0; i < input.length(); i++){
					if (!isdigit(input[i])){
						isValid = false;
						std::cout << "Invalid characters! Please insert a valid Phone Number:\n";
						break;
					}
				}
			}
			newContact.setPhoneNumber(input);

			std::cout << "Please insert Darkest Secret:\n";    
			if (!std::getline(std::cin, input)){
				std::cout << "Exiting at your request!" << std::endl;
				break;
			}
        	while (input.empty()){
            	std::cout << "Please insert Darkest Secret:\n";    
				if (!std::getline(std::cin, input)){
					std::cout << "Exiting at your request!" << std::endl;
					break;
				}
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
