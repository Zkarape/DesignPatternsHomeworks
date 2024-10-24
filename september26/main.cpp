#include <iostream>

class Sandwich
{
    public:
    void setMeat(std::string& meat)
    {
        _meat = meat;
    }
    void setOnion(bool& onion)
    {
        _onion = onion;
    }
    void setCheese(std::string& cheese)
    {
        _cheese = cheese;
    }
     void show() const {
        std::cout << "Sandwich items:\n"
                  << "Meat: " << _meat << "\n"
                  << "Cheese: " << _cheese << "\n"
                  << "Onion: " << _onion;
    }
    private:
        bool _onion;
        std::string _meat;
        std::string _cheese;
};

class buildSandwich
{
public:
    virtual void buildMeat() = 0;
    virtual void buildOnion() = 0;
    virtual void buildCheese() = 0;
    Sandwich* sandwich;
};

class VeggieSandwich : public buildSandwich
{
public:
    void buildOnion() override{
        sandwich->setOnion();
    }
};

class MeatSandwich : public buildSandwich
{
    //overrides
};

class Manager
{
    //Sandwich(buildSandwich)
    //Sandwich(buildSandwich)
};

int main()
{

}