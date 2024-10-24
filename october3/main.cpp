#include <iostream>

class A
{
    public:
    A()
    {
        std::cout << "A is here" << std::endl;
    }
};

class B
{
    public:
    B()
    {
        std::cout << "B is here" << std::endl;
    }
    A &ret_func();
};

int main()
{
    A a;
    B b;

    b.ret_func();
}