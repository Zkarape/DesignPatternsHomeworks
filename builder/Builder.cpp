# include "Builder.hpp"

void Builder::build()
{
}

void Builder::buildStepA(std::string param)
{
    std::cout << "Default implementation of buildStepA()" << std::endl;
}

void Builder::buildStepB(std::string param)
{
    std::cout << "Default implementation of buildStepB()" << std::endl;
}

void Builder::buildStepZ(std::string param)
{
    std::cout << "Default implementation of buildStepZ()" << std::endl;
}

Product *Builder::get_product()
{
    return 0;
}