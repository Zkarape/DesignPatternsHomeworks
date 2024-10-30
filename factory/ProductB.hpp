#ifndef PRODUCTB_HPP
# define PRODUCTB_HPP

# include "Product.hpp"

class ProductB : public Product
{
    public:
        virtual void    doStuff() override;
};

#endif /*PRODUCTB_HPP*/