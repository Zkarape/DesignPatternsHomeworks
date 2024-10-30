#ifndef CREATOR_HPP
# define CREATOR_HPP

# include "Product.hpp"

class Creator // creating product is not a primary responsibility, it has a core business logic related to products, doesn't have to create products all the time, it can also return existing objects
{
    public:
        void            someOperation();
        virtual Product *createProduct();
};

#endif /*CREATOR_HPP*/