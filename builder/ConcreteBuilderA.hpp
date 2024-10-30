#ifndef CONCRETEBUILDERA_HPP
# define CONCRETEBUILDERA_HPP

# include "Builder.hpp"
# include "Product.hpp"

class ConcreteBuilderA : public Builder
{
    private:
        Product    *_product;
    public:
        ConcreteBuilderA();

        void    build() override;
        void    buildStepA(std::string) override;
        void    buildStepB(std::string) override;
        void    buildStepZ(std::string) override;

        Product *get_product();
};

#endif /*CONCRETEBUILDERA_HPP*/