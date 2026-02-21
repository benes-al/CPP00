#include "Contact.hpp"

//Setters
void Contact::setFirstName(const std::string firstName) {
    this->_firstName = firstName;
}
void Contact::setLastName(const std::string lastName){
    this->_lastName = lastName;
}
void Contact::setNickName(const std::string nickName){
    this->_nickName = nickName;
}
void Contact::setPhoneNumber(const std::string phoneNumber){
    this->_phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string darkestSecret){
    this->_darkestSecret = darkestSecret;
}

//Getters
std::string Contact::getFirstName() const{
    return (this->_firstName);
}
std::string Contact::getLastName() const{
    return (_lastName);
}
std::string Contact::getNickName() const{
    return (_nickName);
}
std::string Contact::getPhoneNumber() const{
    return (_phoneNumber);
}
std::string Contact::getDarkestSecret() const{
    return (_darkestSecret);
}
