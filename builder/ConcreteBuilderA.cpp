# include "ConcreteBuilderA.hpp"

ConcreteBuilderA::ConcreteBuilderA()
{
    _product = 0;
}

void    ConcreteBuilderA::build()
{
    _product = new Product();
}

void    ConcreteBuilderA::buildStepA(std::string param)
{
    std::cout << "PartA of ProductA is built using ConcreteBuilder::buildStepA()" << std::endl;
    _product->set_partA(param);
}

void    ConcreteBuilderA::buildStepB(std::string param)
{
    std::cout << "PartA of ProductA is built using ConcreteBuilder::buildStepB()" << std::endl;
    _product->set_partB(param);
}

void    ConcreteBuilderA::buildStepZ(std::string param)
{
    std::cout << "PartA of ProductA is built using ConcreteBuilder::buildStepZ()" << std::endl;
    _product->set_partZ(param);
}

Product    *ConcreteBuilderA::get_product()
{
    return _product;
}