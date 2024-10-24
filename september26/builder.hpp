#ifndef B_HPP
# define B_HPP

#include <iostream>

class Builder
{
private:
    std::string _processor;
    std::string _gpu;
    std::string _battery;
public:
    Builder();
    Builder(std::string &, std::string &, std::string &);
    virtual void buildComputer() = 0;
    virtual ~Builder();
};


#endif