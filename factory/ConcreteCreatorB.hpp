#ifndef CONCRETECREATORB_HPP
# define CONCRETECREATORB_HPP

# include "Creator.hpp"
# include "Product.hpp"
# include "ProductB.hpp"

class ConcreteCreatorB : public Creator
{
    public:
        Product *createProduct() override;
};

#endif /*CONCRETECREATORB_HPP*/