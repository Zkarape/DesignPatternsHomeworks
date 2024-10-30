# include "Singleton.hpp"

Singleton::Singleton()
{
}

Singleton &Singleton::get_instance()
{
    static Singleton s;
    return s;
}

void    Singleton::set_name(std::string name)
{
    _name = name;
}

std::string Singleton::get_name() const
{
    return _name;
}