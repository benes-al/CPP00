#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    //Setters
    void setfirstName(const std::string firstName);
    void setLastName(const std::string lastName);
    void setNickName(const std::string nickName);
    void setPhoneNumber(const std::string phoneNumber);
    void setDarkestSecret(const std::string darkestSecret);

    //Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

};



#endif