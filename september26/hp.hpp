#ifndef HP_HPP
# define HP_HPP


#include "builder.hpp"
#include <iostream>

class HP : public Builder
{
private:
    std::string _processor;
    std::string _gpu;
    std::string _battery;
public:
    HP();
    HP(std::string &, std::string &, std::string &);
    virtual void buildComputer() = 0;
    virtual ~HP();
};


#endif