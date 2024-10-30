#ifndef PRODUCT_HPP
# define PRODUCT_HPP

# include <iostream>

class Product
{
    private:
        std::string   _partA;
        std::string   _partB;
        std::string   _partZ;
    public:
        Product();

        void    set_partA(std::string);
        void    set_partB(std::string);
        void    set_partZ(std::string);

        std::string    get_partA();
        std::string    get_partB();
        std::string    get_partZ();
};

std::ostream &operator<<(std::ostream &, Product &);

#endif /*PRODUCT_HPP*/