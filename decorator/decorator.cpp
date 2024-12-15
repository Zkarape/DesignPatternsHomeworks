#include <iostream>
#include <memory>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle";
    }
};

class ShapeDecorator : public Shape {
protected:
    std::shared_ptr<Shape> wrappedShape;

public:
    ShapeDecorator(std::shared_ptr<Shape> shape) : wrappedShape(std::move(shape)) {}
    virtual ~ShapeDecorator() = default;
};

class DashedLine : public ShapeDecorator {
public:
    DashedLine(std::shared_ptr<Shape> shape) : ShapeDecorator(std::move(shape)) {}

    void draw() const override {
        wrappedShape->draw();
        std::cout << " with Dashed Line";
    }
};

class BoldLine : public ShapeDecorator {
public:
    BoldLine(std::shared_ptr<Shape> shape) : ShapeDecorator(std::move(shape)) {}

    void draw() const override {
        wrappedShape->draw();
        std::cout << " with Bold Line";
    }
};

class DottedLine : public ShapeDecorator {
public:
    DottedLine(std::shared_ptr<Shape> shape) : ShapeDecorator(std::move(shape)) {}

    void draw() const override {
        wrappedShape->draw();
        std::cout << " with Dotted Line";
    }
};

int main() {
    std::shared_ptr<Shape> circle = std::make_shared<Circle>();
    std::shared_ptr<Shape> rectangle = std::make_shared<Rectangle>();

    std::shared_ptr<Shape> dashedCircle = std::make_shared<DashedLine>(circle);
    std::shared_ptr<Shape> boldDashedRectangle = std::make_shared<BoldLine>(
        std::make_shared<DashedLine>(rectangle));

    std::cout << "Simple Shapes:\n";
    circle->draw();
    std::cout << "\n";
    rectangle->draw();
    std::cout << "\n\n";

    std::cout << "Decorated Shapes:\n";
    dashedCircle->draw();
    std::cout << "\n";
    boldDashedRectangle->draw();
    std::cout << "\n";

    return 0;
}