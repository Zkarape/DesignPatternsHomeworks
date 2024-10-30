# include "ConcreteCreatorA.hpp"

Product *ConcreteCreatorA::createProduct()
{
    return new ProductA();
}