#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook{
private:
    Contact _contacts[8];
    int     _quantity;
    int     _index;

public:
    //Setters
    void setContact(const Contact newContact);

    //Getters
    Contact getContact(int index) const;
};

#endif