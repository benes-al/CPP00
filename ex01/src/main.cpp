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
            std::cout << "ADD ok\n";    

            /* newContact.setFirstName(input);
            std::getline(std::cin, input);
            newContact.setLastName(input);
            std::cout << newContact.getLastName() << std::endl; */

        }
    
        else if (input == "SEARCH"){
            std::cout << "Search ok\n";    

        }
    
        else if (input == "EXIT"){
            return (0);
        }
        else
            std::cout << "Please enter a valid command\n";    
    }
    return (0);
}
