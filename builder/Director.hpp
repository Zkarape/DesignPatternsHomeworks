#ifndef DIRECTOR_HPP
# define DIRECTOR_HPP

# include "Builder.hpp"
# include "Product.hpp"

class Director
{
    private:
        Builder _builder;
    public:
        Director();

        Product    *create_productA(Builder &);
        Product    *create_productB(Builder &);

};

#endif /*DIRECTOR_HPP*/