#include "canvas.hpp"

class Canvas;

// Abstract Command Interface
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};


// Concrete Command: Add Shape
class AddShapeCommand : public Command {
private:
    Canvas& canvas;
    std::string shape;

public:
    AddShapeCommand(Canvas& c, const std::string& s) : canvas(c), shape(s) {}

    void execute() override {
        canvas.addShape(shape);
    }

    void undo() override {
        canvas.removeShape();
    }
};

// Concrete Command: Remove Shape
class RemoveShapeCommand : public Command {
private:
    Canvas& canvas;
    std::string lastShape;

public:
    RemoveShapeCommand(Canvas& c) : canvas(c) {}

    void execute() override {
        if (!canvas.getShapes().empty()) {
            lastShape = canvas.getShapes().back(); // Save last shape for undo
            canvas.removeShape();
        }
    }

    void undo() override {
        if (!lastShape.empty()) {
            canvas.addShape(lastShape);
        }
    }
};

// Concrete Command: Draw Canvas
class DrawCommand : public Command {
private:
    Canvas& canvas;

public:
    DrawCommand(Canvas& c) : canvas(c) {}

    void execute() override {
        canvas.draw();
    }

    void undo() override {
        // No-op (drawing doesn't change state)
        std::cout << "Undo not applicable for draw.\n";
    }
};
