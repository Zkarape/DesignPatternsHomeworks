# include "ConcreteCreatorB.hpp"

Product *ConcreteCreatorB::createProduct()
{
    return new ProductB();
}