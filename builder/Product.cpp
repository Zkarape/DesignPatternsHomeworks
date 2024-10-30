# include "Product.hpp"

Product::Product(): _partA("undone"), _partB("undone"), _partZ("undone")
{
    std::cout << "Defualt ctor of Product" << std::endl;
}

void    Product::set_partA(std::string param)
{
    _partA = param;
}

void    Product::set_partB(std::string param)
{
    _partB = param;
}

void    Product::set_partZ(std::string param)
{
    _partZ = param;
}

std::string Product::get_partA()
{
    return _partA;
}

std::string Product::get_partB()
{
    return _partB;
}

std::string Product::get_partZ()
{
    return _partZ;
}

std::ostream &operator<<(std::ostream &o, Product &p)
{
    o << p.get_partA() << std::endl;
    o << p.get_partB() << std::endl;
    o << p.get_partZ() << std::endl;
    return o;
}
