#include "prototype.hpp"

#include <iostream>
#include <memory>


struct Address
{
    Address(const std::string  &_street, const std::string & _city, const int _suite) : street(_street), city(_city), suite(_suite) {};
    std::string street, city;
    int suite;
};

struct Contact
{
    Contact(const std::string &_name, const Address &_addr) : name(_name), address(_addr) 
    {
        std::cout << "Constructor is called" << std::endl;
    };
    std::string name;
    Address address;
};



struct EmployeeFactory
{
    private:
        static Contact main;
        static Contact aux;

    public:

        static std::unique_ptr<Contact> NewMainOfficeEmployee(const std::string& name, const int suite)
        {
            return NewEmployee(name, suite, main);
        }

        static std::unique_ptr<Contact> NewAuxOfficeEmployee(const std::string& name, const int suite)
        {
            return NewEmployee(name, suite, aux);
        }

    private:
        static std::unique_ptr<Contact> NewEmployee(
            const std::string& name, const int suite, const Contact &proto)
        {
            auto result = std::make_unique<Contact>(proto);

            result->name = name;
            result->address.suite = suite;

            return result;
        }
};



Contact EmployeeFactory::main = Contact("John", Address("Arshakunyats", "London", 123));
Contact EmployeeFactory::aux = Contact("Joe", Address("Arsh", "Yerevan", 125));

int main()
{
    std::unique_ptr<Contact> John = EmployeeFactory::NewMainOfficeEmployee("John", 1);
    std::unique_ptr<Contact> Joe = EmployeeFactory::NewAuxOfficeEmployee("Joe", 2);

    std::cout << "John->name == " << John->name << "John->address.city" << John->address.city << std::endl;
    std::cout << "Joe->name == " << Joe->name << "Joe->address.city" << Joe->address.city << std::endl;
}