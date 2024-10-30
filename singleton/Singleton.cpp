# include "Singleton.hpp"

Singleton   *Singleton::_instance = nullptr;

Singleton::Singleton()
{
}

Singleton *Singleton::get_instance()
{
    if (_instance == nullptr)
        _instance = new Singleton();
    return _instance;
}