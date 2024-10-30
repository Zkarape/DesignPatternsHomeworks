#ifndef BUILDER_HPP
# define BUILDER_HPP

# include <iostream>

# include "Product.hpp"

class Builder
{
    public:
        virtual void    build();
        virtual void    buildStepA(std::string);
        virtual void    buildStepB(std::string);
        virtual void    buildStepZ(std::string);

        Product     *get_product();
};

#endif /*BUILDER_HPP*/