# include "ConcreteBuilderA.hpp"
# include "Director.hpp"
# include "Product.hpp"
# include "Builder.hpp"

int main()
{
    Product            *product;
    Director            director;
    ConcreteBuilderA    builderA;

    director.create_productA(builderA);
    product = builderA.get_product();
    std::cout << *product << std::endl;

    director.create_productB(builderA);
    product = builderA.get_product();
    std::cout << *product << std::endl;

}