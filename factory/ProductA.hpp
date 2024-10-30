#ifndef PRODUCTA_HPP
# define PRODUCTA_HPP

# include "Product.hpp"

class ProductA : public Product
{
    public:
        virtual void    doStuff() override;
};

#endif /*PRODUCTA_HPP*/