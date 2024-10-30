# include <iostream>

# include "Singleton.hpp"

int main()
{
    Singleton::get_instance().set_name("s1");
    std::cout << "Singelton name: " << Singleton::get_instance().get_name() << std::endl;
    Singleton::get_instance().set_name("s2");
    std::cout << "Singelton name: " << Singleton::get_instance().get_name() << std::endl;
}