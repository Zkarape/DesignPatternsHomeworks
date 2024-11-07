#pragma once

#include <iostream>
#include <string>
#include <memory>


class IShape
{
    public:
        virtual void draw() const = 0;
        virtual ~IShape() = 0;
};

class Circle : public IShape
{
    void draw() const override
    {
        std::cout << "The Circle is drawn: " << std::endl;
    };
};

class Rectangle : public IShape
{
    void draw() const override
    {
        std::cout << "The Rectangle is drawn: " << std::endl;
    };
};

class ShapeDecorator : public IShape
{
    private:
        const std::shared_ptr<IShape>& shape;
    public:
        ShapeDecorator(std::shared_ptr<IShape> s) : shape(std::move(s)) {}

        void draw() const override
        {
            shape->draw(); // Delegates the call to the wrapped shape
        }
};


class BorderDecorator : public ShapeDecorator {
private:
    int borderThickness;

public:
    BorderDecorator(std::shared_ptr<IShape> s, int thickness)
        : ShapeDecorator(std::move(s)), borderThickness(thickness) {}

    void draw() const override {
        ShapeDecorator::draw();
        std::cout << " with border thickness " << borderThickness;
    }
};


int main()
{
    std::shared_ptr<IShape> rect(std::make_shared<IShape>);

    ShapeDecorator decor(rect);
    decor.draw();
    BorderDecorator borddecor(rect, 5);
    borddecor.draw();
}