#ifndef CONCRETECREATORA_HPP
# define CONCRETECREATORA_HPP

# include "Creator.hpp"
# include "Product.hpp"
# include "ProductA.hpp"

class ConcreteCreatorA : public Creator
{
    public:
        Product *createProduct() override;
};

#endif /*CONCRETECREATORA_HPP*/