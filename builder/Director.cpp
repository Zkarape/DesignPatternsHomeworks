# include "Director.hpp"

Director::Director()
{
}

Product    *Director::create_productA(Builder &builder)
{
    builder.build();
    builder.buildStepA("partA of productA");
    builder.buildStepB("partB of productA");
    return builder.get_product();
}

Product    *Director::create_productB(Builder &builder)
{
    builder.build();
    builder.buildStepA("partA of productB");
    builder.buildStepB("partB of productB");
    builder.buildStepZ("partZ of productB");
    return builder.get_product();
}