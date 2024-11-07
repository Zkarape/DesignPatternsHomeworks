#include <iostream>
#include <string>
#include <memory>


class IShape
{
    public:
        virtual void draw() const = 0;
        virtual ~IShape() {};
};

class Circle : public IShape
{
    public:
        void draw() const override
        {
            std::cout << "The Circle is drawn: " << std::endl;
        };
        ~Circle() = default;
};

class Rectangle : public IShape
{
    public:

        void draw() const override
        {
            std::cout << "The Rectangle is drawn: " << std::endl;
        };
        ~Rectangle() = default;
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
        virtual ~ShapeDecorator() = default;
};


class BorderDecorator : public ShapeDecorator {
private:
    int borderThickness;

public:
    BorderDecorator(std::shared_ptr<IShape> s, int thickness)
        : ShapeDecorator(std::move(s)), borderThickness(thickness) {}

    void draw() const override {
        // ShapeDecorator::draw();
        std::cout << " with border thickness " << borderThickness;
    }
    ~BorderDecorator() = default;
};


int main()
{
    std::shared_ptr<IShape> rect = std::make_shared<Rectangle>();

    ShapeDecorator decor(rect);
    decor.draw();
    BorderDecorator borddecor(rect, 5);
    borddecor.draw();
}